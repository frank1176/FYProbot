

### rasberry pi 
## go root
sudo su -



# setting ip

nano /etc/dhcpcd.conf


######YOLOV7#############

sudo apt-get update
sudo apt-get install python3-dev python3-pip libatlas-base-dev
git clone https://github.com/WongKinYiu/yolov7

cd yolov7
pip3 install -r requirements.txt
wget https://pjreddie.com/media/files/yolov7.weights
python3 detect.py --image <path_to_image>
#########################


######YOLOV5#############
sudo apt-get update
sudo apt-get install python3-dev python3-pip
pip3 install numpy opencv-python onnxruntime
git clone https://github.com/ultralytics/yolov5

cd yolov5
wget https://github.com/ultralytics/yolov5/releases/download/v5.0/yolov5s.onnx
python3 detect.py --weights yolov5s.onnx --img 640 --conf 0.5 --source 0

#########################