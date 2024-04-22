# ros2CV

## 3.24

本地topic实现服务器端调用摄像头，客户端接收Image消息进行霍夫圆检测

rosAPI：https://docs.ros.org/en/api/

## 3.30

话题实现服务端yolo检测，客户端接收图片

## 3.31

使用话题，一端打开摄像头并发布图像话题，另一端接收图像并进行处理，同时发布坐标话题，摄像头端发布同时订阅坐标话题

未解决：cmake

## 4.5-6

解决cmake的问题——:cry: 新建话题接口，并修改cmake（ament_target_dependencies）

未解决：加载onnx模型

## 4.20-21

加载onnx，实现话题互传
