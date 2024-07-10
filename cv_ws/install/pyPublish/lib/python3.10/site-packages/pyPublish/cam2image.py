#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# 导入ROS 2 Python库
import rclpy                            # ROS2 Python接口库
from rclpy.node import Node

# 导入sensor_msgs下的Image消息类型，用于发布图像数据
from sensor_msgs.msg import Image

# 导入OpenCV库
import cv2
# 导入cv_bridge，这是ROS和OpenCV之间的桥梁，用于转换图像数据格式
from cv_bridge import CvBridge
# 定义CustomCam2Image类，继承自Node
import numpy as np # 导入 Numpy 库，用于进行一些数学和矩阵运算
class CustomCam2Image(Node):
    def __init__(self):
        # 调用父类的构造函数，节点名字为'custom_cam2image'
        super().__init__('cam2image')

        # 声明并获取节点参数，包括width、height、frequency、device_id
        # 这些参数用于配置摄像头的图像尺寸、帧率和设备ID
        self.declare_parameter('width', 640)
        self.declare_parameter('height', 640)
        self.declare_parameter('frequency', 60.0)
        self.declare_parameter('device_id', -1)
        self.jpeg_quality = 50  # 初始JPEG质量值

        self.width = self.get_parameter('width').get_parameter_value().integer_value
        self.height = self.get_parameter('height').get_parameter_value().integer_value
        self.frequency = self.get_parameter('frequency').get_parameter_value().double_value
        self.device_id = self.get_parameter('device_id').get_parameter_value().integer_value

        # 初始化摄像头捕获
        self.cap = cv2.VideoCapture(self.device_id)

        if not self.cap.isOpened():  # 检查设备是否成功打开
            self.get_logger().error('Could not open video device')
            # 如果无法打开设备，打印错误日志
            exit(1)

        # 设置摄像头的图像尺寸和帧率
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.width)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.height)
        self.cap.set(cv2.CAP_PROP_FPS, self.frequency)

        # 初始化cv_bridge，用于ROS和OpenCV图像格式之间的转换
        self.bridge = CvBridge()
        
        
        # 创建图像数据的发布者，主题名为'image_raw'
        self.publisher_ = self.create_publisher(Image, 'image_raw', 10)



        # 根据指定帧率创建定时器，定时调用timer_callback函数
        timer_period = 1 / self.frequency  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        # 从摄像头读取一帧图像
        ret, frame = self.cap.read()
        if ret:
            # 压缩图像为JPEG格式
            encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), self.jpeg_quality]
            result, encimg = cv2.imencode('.jpg', frame, encode_param)
            if not result:
                raise RuntimeError('Could not encode image!')

            # 将压缩的图像二进制数据转换为1D Numpy数组
            msg_data = np.array(encimg).tostring()

            # 使用cv_bridge构建Image消息的一部分
            msg_header = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8').header

            # 创建Image消息
            msg = Image(header=msg_header, height=frame.shape[0], width=frame.shape[1],
                        encoding='jpeg', is_bigendian=0, step=len(msg_data), data=msg_data)

            msg.encoding = '8UC1'  # 或使用 'mono8'，这样订阅者节点就不会因为无法识别而出错
            msg.height = 1
            msg.width = len(msg_data)
            msg.step = len(msg_data)
            msg.data = np.array(encimg).tobytes()

            # 发布消息
            self.publisher_.publish(msg)
            self.get_logger().info('Publishing compressed camera image')


        else:
            # 如果没有成功读取图像，记录警告信息
            self.get_logger().warn('No frames')
        # 输出日志信息，提示已经完成图像话题发布
        self.get_logger().info('Publishing video frame')  # 输出日志信息，提示已经完成图像话题发布


# main函数，程序入口
def main(args=None):
    # 初始化ROS 2
    rclpy.init(args=args)
    # 创建CustomCam2Image节点实例
    node = CustomCam2Image()
    try:
        # 循环运行节点，直到收到终止信号
        rclpy.spin(node)
    except KeyboardInterrupt:
        # 收到Ctrl+C时，输出信息并优雅关闭节点
        node.get_logger().info('Keyboard interrupt, shutting down.')
    finally:
        # 释放摄像头资源，销毁节点和关闭ROS 2
        node.cap.release()
        node.destroy_node()
        rclpy.shutdown()


# 如果该文件被当作主模块执行，运行main函数
if __name__ == '__main__':
    main()
