
// #include "rclcpp/rclcpp.hpp"
// #include "sensor_msgs/msg/image.hpp"
// #include "cv_bridge/cv_bridge.h"
// #include "opencv2/opencv.hpp"

// class ImagePublisher : public rclcpp::Node {
// public:
//     ImagePublisher() : Node("topic_webcam_pub_cpp") {
//         publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image_raw", 10);
//         timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&ImagePublisher::timer_callback, this));
//         cap.open(0, cv::CAP_V4L2);
//         cv_bridge = cv_bridge::CvImage();
//     }

// private:
//     void timer_callback() {
//         cv::Mat frame;
//         cap >> frame;

//         if (!frame.empty()) {
//             auto img_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
//             publisher_->publish(*img_msg);
//         }

//         RCLCPP_INFO(this->get_logger(), "Publishing video frame");
//     }

//     rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
//     rclcpp::TimerBase::SharedPtr timer_;
//     cv::VideoCapture cap;
//     cv_bridge::CvImage cv_bridge;
// };

// int main(int argc, char** argv) {
//     rclcpp::init(argc, argv);
//     auto node = std::make_shared<ImagePublisher>();
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"

using namespace cv;

class imagePub : public rclcpp::Node
{
public:
    imagePub() : Node("webcam_pub")
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&imagePub::timer_callback, this));
        cap.open(0, CAP_V4L2);
        cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
        cap.set(CAP_PROP_FRAME_WIDTH, 640);//图像的宽
        cap.set(CAP_PROP_FRAME_HEIGHT, 480);//图像的高
    }
private:
    void timer_callback()
    {
        Mat frame;
        cap >> frame;
        if (frame.rows > 0 && frame.cols > 0)
        {
            auto img_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
            publisher_->publish(*img_msg);
        }
        RCLCPP_INFO(this->get_logger(), "Publishing video frame");
    }
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    VideoCapture cap;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<imagePub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
