#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/dnn/dnn.hpp"
#include "cv_bridge/cv_bridge.h"
#include <iostream>
//#include <topic_interfaces/msg/coord.hpp>
#define USE_CUDA true


using namespace cv;
using namespace std;
using namespace cv::dnn;

string model_path = "./models/bestv5.onnx";
string model_path_circle = "./models/best_circle.onnx";

class imageSub : public rclcpp::Node
{
public:
    imageSub() : Node("webcam_sub"){
        
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>("image", 10, std::bind(&imageSub::image_callback, this, std::placeholders::_1));
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;

    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Receiving video frames");
        //auto image = cv_bridge::CvImage::toCompressedImageMsg(cv_bridge::JPG);
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        Mat image = cv_ptr->image;
        imageSub::cicleDetect(image);
    }

    void cicleDetect(Mat src)
    {
        Mat dst, out;
        cvtColor(src, dst, COLOR_RGB2GRAY);
        bilateralFilter(dst, out, 3, 100, 100);
        std::vector<Vec3f> circles;
        HoughCircles(out, circles, HOUGH_GRADIENT_ALT, 1.5, 500, 300, 0.8);
        for (size_t i = 0; i < circles.size(); i++)
        {
            Vec3f c = circles[i];
            circle(src, Point(c[0], c[1]), c[2], Scalar(0, 255, 255), 3, LINE_AA);
            circle(src, Point(c[0], c[1]), 2, Scalar(255, 0, 0), 3, LINE_AA);
            // cout << "x = " << c[0] << "y = " << c[1] << endl;
            // char * xx;
            // char * yy;
            // cout << 1 << endl;
            // sprintf(xx, "%.3f", c[0]);
            // sprintf(yy, "%.3f", c[1]);
            // cout << 2 << endl;
            // strcpy(coord, xx);
            // strcat(coord, ",");
            // strcat(coord, yy);
            // cout << 3 << endl;

        }
        imshow("object", src);
        waitKey(1);
    }


};

bool readModel(Net &net, string &netPath, bool isCuda = false)
{
    try
    {
        net = readNet(netPath);
    }
    catch (const std::exception &)
    {
        return false;
    }
    // cuda
    if (isCuda)
    {
        net.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
        net.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
    }
    // cpu
    else
    {
        net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
        net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }
    return true;
}
int main(int argc, char ** argv)
{
    cout << CV_VERSION << endl;
    Net net1, net2, net3;
    if (readModel(net1, model_path, USE_CUDA))
    {
        cout << "read net1 ok!" << endl;
    }else{
        cout << "read onnx1 model failed!";
    }
    if (readModel(net2, model_path_circle, USE_CUDA))
    {
        cout << "read net2 ok!" << endl;
    }else{
        cout << "read onnx2 model failed!";
    }

    // rclcpp::init(argc, argv);
    // auto node = std::make_shared<imageSub>();
    // rclcpp::spin(node);
    // rclcpp::shutdown();
    return 0;

}