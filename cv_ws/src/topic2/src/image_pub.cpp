#include "global.hpp"
#include "yolo.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "rclcpp/rclcpp.hpp"
#include "cv_bridge/cv_bridge.h"
#include "ros2_interfaces/msg/coord.hpp"

using namespace Eigen;
using namespace std;
using namespace cv;
using namespace cv::dnn;

char coord[50];

class imagePub : public rclcpp::Node
{
public:
    imagePub() : Node("image_pub")
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&imagePub::timer_callback, this));
        subscriber_ = this->create_subscription<ros2_interfaces::msg::Coord>("coord", 10, std::bind(&imagePub::coord_callback, this, std::placeholders::_1));
        cap.open(0, CAP_V4L2);
        cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
        cap.set(CAP_PROP_FRAME_WIDTH, 640);//图像的宽
        cap.set(CAP_PROP_FRAME_HEIGHT, 480);//图像的高
    }
private:
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::Subscription<ros2_interfaces::msg::Coord>::SharedPtr subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;
    VideoCapture cap;

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

    void coord_callback(const ros2_interfaces::msg::Coord::SharedPtr msg)
    {
        int x = msg->x;
        int y = msg->y;
        RCLCPP_INFO(this->get_logger(), "收到坐标(%d, %d)", x, y);
    }
    
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<imagePub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
