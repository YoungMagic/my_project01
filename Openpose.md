### 在视频上运行
# Ubuntu
./build/examples/openpose/openpose.bin --video examples/media/video.avi

### 在图片上运行
# Ubuntu
./build/examples/openpose/openpose.bin --image_dir examples/media/

### 最精确
# Ubuntu
./build/examples/openpose/openpose.bin --net_resolution "1312x736" --scale_number 2 --scale_gap 0.25 --hand --hand_scale_number 3 --hand_scale_range 0.4 --face --video examples/media/video.avi

### 输出信息
./build/examples/openpose/openpose.bin --image_dir examples/media/ --write_keypoint=XML

./build/examples/openpose/openpose.bin --image_dir examples/media/ --write_keypoint_json examples/media_out 
#### 保存视频
./build/examples/openpose/openpose.bin --video examples/media/MyVdeoFFmpeg.avi --write_video output/my/1.avi --write_keypoint_json output/my/

./build/examples/openpose/openpose.bin --image_dir examples/media/ --write_images output/image/ --write_keypoint_json output/image/

./build/examples/openpose/openpose.bin --ip_camera http://iris.not.iac.es/axis-cgi/mjpg/video.cgi?resolution=320x240?x.mjpeg

###
./build/examples/openpose/openpose.bin --ip_camera http://iris.not.iac.es/axis-cgi/mjpg/video.cgi?resolution=320x240?x.mjpeg

./build/examples/openpose/openpose.bin --ip_camera rtsp://admin:12345@192.168.1.88:554/h264/ch1/main/av_strea5 --process_real_time -write_video output/my/1.avi --write_keypoint_json output/my/


### 所需点位信息
include/openpose/pose/poseParameters.hpp里点位信息
```
  {1,  "Neck"},
  {2,  "RShoulder"},
  {3,  "RElbow"},
  {4,  "RWrist"},
  {5,  "LShoulder"},
  {6,  "LElbow"},
  {7,  "LWrist"},
  {8,  "RHip"},
  {9,  "RKnee"},
  {11, "LHip"},
  {12, "LKnee"},
  一共11个点
 ```
 <p align="center">
    <img src="https://raw.githubusercontent.com/YoungMagic/my_project01/master/media/keypoints_pose.png">
</p>

 调整输出范围 flag keypoint_scale
 include/openpose/filestream/fileStream.hpp里的 ```loadData ```和 ```loadData ```来读取文件

