#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

class Image 
class webcamServer : public rclcpp::Node
{
public:
    webcamServer(string name) : Node(Server)
    {
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
        server_ = this->create_service<ros_interfaces::srv::transferImage>("transfer_image", std::bind(&webcamServer::handle_image, this, std::placeholders::_1, std::placeholders::_2));
    
    }
private:
    rclcpp::Service<ros2_interfaces::srv::transferImage>::SharedPtr server_;

    void handle_image(const std::shared_ptr<ros_interfaces::srv::transferImage::Request> request, std::shared_ptr<ros_interfaces::srv::transferImage::Response> response)
    {
        RCLCPP_INFO(this->get_logger(), "收到图像数据");
        Image
    } 
};

int main()
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<webcamServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
