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

class imagePub : public rclcpp::Node
{
public:
    imagePub() : Node("image_pub")
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image", 10);
        readModel();
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&imagePub::timer_callback, this));
        cap.open(0);
        cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
        cap.set(CAP_PROP_FRAME_WIDTH, 640);//图像的宽
        cap.set(CAP_PROP_FRAME_HEIGHT, 480);//图像的高
    }
private:
    rclcpp::publisher<sensor_msgs::msgs::Image>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    VideoCapture cap;
    Yolo test;
    Net net1, net2;
    vector<Output> result;

    void readModel()
    {
        if (test.readModel(net1, model_path, USE_CUDA))
        {
            cout << "read net1 ok!" << endl;
        }else{
            cout << "read onnx1 model failed!";
            return -1;
        }
        if (test.readModel(net2, model_path_circle, USE_CUDA))
        {
            cout << "read net2 ok!" << endl;
        }else{
            cout << "read onnx2 model failed!";
            return -1;
        }
    }

    void timer_callback()
    {
        Mat frame, img;
        cap >> frame;
        img = handle_image(frame, test);
        auto img_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
        publisher_->publish(*img_msg);
        RCLCPP_INFO(this->get_logger(), "Publishing video frame");
        
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

        Mat src;
        undistort(frame, src, K, D, K);
        if (test.Detect(src, net1, result, 1))
        {
            src = test.drawPred(src, result, color, 1);
        }
        if (test.Detect(src, net2, result, 0))
        {
            test.target(src, result, 0);
            src = test.drawPred(src, result, color, 0);
        }

        return src;
    }
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
        if (count_servo >= times)
            flag_servo = 1;
            model_flag = 1;
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


int main(int argc, char ** argv)
{
    coord[0] = '0';
    rclcpp::init(argc, argv);
    auto node = std::make_shared<imagePub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}