#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"

using namespace cv;

class imageSub : public rclcpp::Node
{
public:
    imageSub() : Node("webcam_sub"){
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>("image", 10, std::bind(&imageSub::image_callback, this, std::placeholders::_1));
    }
private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
    void image_callback()
    {
        RCLCPP::INFO(this->get_logger, "Receiving video frames", )
    }
    void cicleDetect
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<imageSub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}