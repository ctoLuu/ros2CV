#include "global.h"
#include "ros_interfaces/srv/transfer_image"

class webcamClient : public rclcpp::Node
{
public:
    webcamClient(std::string name) : Node (Client){
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
        client_ = this->create_client<ros_interfaces::srv::transfer_image>("transfer_image");
        cap.open(0, CAP_V4L2);
        cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
        cap.set(CAP_PROP_FRAME_WIDTH, 640);//图像的宽
        cap.set(CAP_PROP_FRAME_HEIGHT, 480);//图像的高
    }
private:
    void transfer_image(VideoCapture cap)
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
}