#include "global.h"

class imageSub : public rclcpp::Node
{
public:
    imageSub() : Node("image_sub")
    {
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
        namedWindow("frame", WINDOW_NORMAL);
        imshow("frame", image);
        resizeWindow("frame", 1040, 780);
        moveWindow("frame", 0, 330);        
    }
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<imageSub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}