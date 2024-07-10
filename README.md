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

## 5.-7.

实现在树莓派实现传输图像，本地处理图像并回传目标坐标

## 7-9

# Other

## LFS

```shell
git lfs track "*.pdf"  // 选择LFS追踪的文件
git push --no-verify  // 包含LFS文件但不推送
git lfs ls-files  // 查看正在被追踪的文件
git lfs untrack "*.png"  // 取消追踪
git add .gitattributes  // 保存提交配置
git lfs migrate import --include-ref=main --include="*.png" // 对现存文件应用LFS且改写提交历史
git lfs migrate import --no-rewrite -m "lfs import"  // 不改写提交历史
git push origin main --force  // 改写提交历史需要强制推送
```

