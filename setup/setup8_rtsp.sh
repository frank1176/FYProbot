
sudo su -

apt-get -y install cmake liblog4cpp5-dev libv4l-dev

git clone https://github.com/mpromonet/v4l2rtspserver.git

cd v4l2rtspserver

cmake . && make

make install

v4l2rtspserver -F 30 -W 640 -H 480 -P 8554 /dev/video0
v4l2rtspserver -F 60 -W 640 -H 480 -P 8554 /dev/video0


# yolov5 
python detect.py --source rtsp://engineer:anakperantau@192.168.0.23:8554/unicast --weights yolov5s.pt

######
sudo apt-get update
apt-get install v4l-utils vlc
cvlc v4l2:///dev/video0 --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264
su engineer -c "cvlc v4l2:///dev/video0 --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264"
su engineer -c "cvlc v4l2:///dev/video0:chroma=h264:width=640:height=480 --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264"