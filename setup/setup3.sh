

### rasberry pi 
## go root
sudo su -
apt update && apt -y dist-upgrade
raspi-config

# setting ip

nano /etc/dhcpcd.conf

###kenny 192.168.0.25


###########setup cam ################

# apt -y install motion
# mkdir -p /var/log/motion
# chmod -R 777 /var/log/motion
# service motion restart
# service motion status
# service motion start
# service motion stop

# ##start open port
# motion
# kill -9 1399

# nano /etc/motion/motion.conf

# deamon -> on
# webcontrol_localhost -> off
# stream_localhost -> off
#movie_output -> off
#####################################


######YOLOV5#############
sudo su -
apt -y install python3 python3-pip libgl1
apt -y install libatlas-base-dev
apt update && apt -y dist-upgrade 
exit
cd ~
git clone https://github.com/ultralytics/yolov5
cd yolov5
pip install opencv-python torch pandas psutil torchvision pyyaml tqdm ultralytics
# pip install -r requirements.txt 
# wget https://github.com/ultralytics/yolov5/releases/download/v5.0/yolov5s.onnx
#test#
python detect.py --weights yolov5s.pt --source 0
python3 detect.py --weights yolov5s.onnx --img 640 --conf 0.5 --source 0
python3 detect.py --source data/images --weights yolov5s.pt --conf 0.25
python3 detect.py --source 0 --weights yolov5s.pt --conf 0.25
