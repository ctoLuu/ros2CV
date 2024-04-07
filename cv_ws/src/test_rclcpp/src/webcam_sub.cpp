#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include <iostream>
//#include <topic_interfaces/msg/coord.hpp>

using namespace cv;
using namespace std;

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

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<imageSub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}