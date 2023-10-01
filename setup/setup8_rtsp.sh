
sudo su -

apt-get -y install cmake liblog4cpp5-dev libv4l-dev

git clone https://github.com/mpromonet/v4l2rtspserver.git

cd v4l2rtspserver

cmake . && make

make install

v4l2rtspserver -F 30 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 60 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 15 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 10 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 5 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 20 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 0 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 60 -W 640 -H 480 -P 8554 /dev/video0
# v4l2rtspserver -v -c -F 20 -W 640 -H 480 -P 8554 /dev/video0
# v4l2rtspserver -F 15 -W 640 -H 480 -P 8554 /dev/video0
# v4l2rtspserver --rtsp-tcp /dev/video0
# v412-ctl -c repeat_sequence_header=1
# v4l2rtspserver -c

# yolov5 
python detect.py --source rtsp://engineer:anakperantau@192.168.0.23:8554/unicast --weights yolov5s.pt
python detect.py --source rtsp://engineer:anakperantau@192.168.0.26:8554/unicast --weights yolov5s.pt --classes 67 --name exp --exist-ok --nosave
python detect.py --source rtsp://engineer:anakperantau@192.168.0.26:8554/unicast --weights best.pt --conf 0.7 --name wastedetection --exist-ok --nosave
python detect.py --source rtsp://engineer:anakperantau@192.168.0.26:8554/unicast --weights best.pt --conf 0.7 --name wastedetection --exist-ok --nosave
python detect.py --source rtsp://engineer:anakperantau@192.168.0.26:8554/unicast --weights runs/train/exp7/weights/best.pt --conf 0.7 --name wastedetection --exist-ok --nosave
python detect.py --source rtsp://engineer:anakperantau@192.168.0.26:8554/unicast --weights runs/train/exp7/weights/last.pt --conf 0.7 --name wastedetection --exist-ok --nosave
python detect.py --source rtsp://engineer:anakperantau@192.168.0.26:8554/unicast --weights runs/train/exp4/weights/last.pt  --name wastedetection --exist-ok --nosave
python detect.py --source rtsp://engineer:anakperantau@192.168.0.26:8554/unicast --weights runs/train/exp4/weights/best.pt  --name wastedetection --exist-ok --nosave

# laptop
python detect.py --source rtsp://engineer:anakperantau@192.168.100.26:8554/unicast --weights detect-pt/exp6/weights/best.pt --conf 0.7 --name wastedetection --exist-ok --nosave
######
sudo apt-get update
apt-get install v4l-utils vlc
cvlc v4l2:///dev/video0 --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264
su engineer -c "cvlc v4l2:///dev/video0 --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264"
su engineer -c "cvlc v4l2:///dev/video0:chroma=h264:width=640:height=480 --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264"