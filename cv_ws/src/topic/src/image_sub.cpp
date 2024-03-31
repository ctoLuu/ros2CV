#include "global.h"

#define USE_CUDA true

char coord[50];
char coord_last_frame[50];
int target_x = 320;
int target_y = 240;
int flag_servo = 0;
int count_servo = 0;
int count_nomove = 0;
int model_flag = 0;
string model_path = "../models/bestv5.onnx";
string model_path_circle = "../models/best_circle.onnx";
Matrix3d K; // 内参矩阵
Vector2d D; // 畸变矩阵

class imageSub : public rclcpp::Node
{
public:
    imageSub() : Node("webcam_sub"){
        readmodel();
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>("image", 10, std::bind(&imageSub::image_callback, this, std::placeholders::_1));
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
    rclcpp::Publisher<topic_interfaces::msg::Coord>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    VideoCapture cap;
    Yolo test;
    Net net1, net2;
    vector<Output> result;

    void readmodel()
    {
        if (test.readModel(net1, model_path, USE_CUDA))
        {
            cout << "read net1 ok!" << endl;
        }else{
            cout << "read onnx1 model failed!";
        }
        if (test.readModel(net2, model_path_circle, USE_CUDA))
        {
            cout << "read net2 ok!" << endl;
        }else{
            cout << "read onnx2 model failed!";
        }
    }

    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Receiving video frames");
        //auto image = cv_bridge::CvImage::toCompressedImageMsg(cv_bridge::JPG);
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        Mat src = cv_ptr->image;

        Mat img;
        img = handle_image(src, test);
        namedWindow("frame", WINDOW_NORMAL);
        imshow("frame", img);
        resizeWindow("frame", 1040, 780);
        moveWindow("frame", 0, 330);

        drive_servo(coord, target_x, target_y, 60);
        if (strcmp(coord, coord_last_frame) == 0)
        { // 如果连续多帧坐标相同，说明没有检测到目标，不再发送坐标数据
            count_nomove++;
            if (count_nomove >= 30)
            {
                strcpy(coord, "0");
                count_nomove = 0;
            }
        }

        publisher_ = this->create_publisher<topic_interfaces::msg::Coord>("coord", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&imageSub::timer_callback, this));
        strcpy(coord_last_frame, coord);
    }

    Mat handle_image(Mat frame, Yolo test)
    {
        cv::Mat K = (cv::Mat_<double>(3, 3) << 514.0045, 0, 321.6074,
                                        0, 514.6655, 260.0872,
                                        0, 0, 1);
        cv::Mat D = (cv::Mat_<double>(4, 1) << 0.1631, -0.2023, 0, 0);
        vector<Scalar> color;

        srand(time(0));
        for (int i = 0; i < 80; i++)
        {
            int b = rand() % 256;
            int g = rand() % 256;
            int r = rand() % 256;
            color.push_back(Scalar(b, g, r));
        }

        Mat img;
        undistort(frame, img, K, D, K);
        if (test.Detect(img, net1, result, 1))
        {
            img = test.drawPred(img, result, color, 1);
        }
        if (test.Detect(img, net2, result, 0))
        {
            test.target(img, result, 0);
            img = test.drawPred(img, result, color, 0);
        }
        return img;
    }

    void timer_callback()
    {
        topic_interfaces::msg::Coord message;
        sscanf(coord, "%d,%d,%d", &message.x, &message.y, &message.flag_servo);
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "publish coord");
    }

    void drive_servo(char *str, int target_x, int target_y, int times)
    {
        int x, y, r;
        int rmax = 50;
        if (sscanf(str, "%d,%d", &x, &y) == 2)
        {
            r = calculateDistance(x, y, target_x, target_y);

            if (r <= rmax)
                count_servo++;
            else
                count_servo = 0;
            cout << r << "|" << count_servo << endl;
            if (count_servo >= times){
                flag_servo = 1;
                model_flag = 1;
            }
        }
    }

// 计算两点间距离
    double calculateDistance(double x1, double y1, double x2, double y2)
    {
        double dx = x2 - x1;
        double dy = y2 - y1;
        double distance = std::sqrt(dx * dx + dy * dy);
        return distance;
    }
};



int main(int argc, char ** argv)
{
    coord[0] = '0';
    rclcpp::init(argc, argv);
    auto node = std::make_shared<imageSub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}