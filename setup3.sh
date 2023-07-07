

### rasberry pi 
## go root
sudo su -
apt update && apt -y dist-upgrade
raspi-config

# setting ip

nano /etc/dhcpcd.conf

###kenny 192.168.0.25


###########setup cam ################

apt -y install motion
mkdir -p /var/log/motion
chmod -R 777 /var/log/motion
service motion restart
service motion status
service motion start
service motion stop

##start open port
motion
kill -9 1399

nano /etc/motion/motion.conf

# deamon -> on
# webcontrol_localhost -> off
# stream_localhost -> off
#movie_output -> off
#####################################

# ######YOLOV7#############

# sudo apt-get update
# sudo apt-get install python3-dev python3-pip libatlas-base-dev
# git clone https://github.com/WongKinYiu/yolov7

# cd yolov7
# pip3 install -r requirements.txt
# wget https://pjreddie.com/media/files/yolov7.weights
# python3 detect.py --image <path_to_image>
# #########################


######YOLOV5#############
sudo su 
apt update && apt -y dist-upgrade 
apt -y install python3-dev python3-pip

wget https://www.python.org/ftp/python/3.11.1/Python-3.11.1.tgz
tar -xzvf Python-3.11.1.tgz
cd Python-3.11.1/

apt update && apt dist-upgrade
apt -y install build-essential zlib1g-dev libncurses5-dev libgdbm-dev \
    libnss3-dev libssl-dev libreadline-dev libffi-dev libsqlite3-dev wget libbz2-dev python3-pip


apt update && apt dist-upgrade
./configure --enable-optimizations
make -j$(nproc) && make altinstall
cd ~
rm -rf Python-3.11.1
rm -rf Python-3.11.1.tgz

python -V

python3.11 -V

##make python 3.11 the default version
ln -s /usr/local/bin/python
ln -s /usr/local/bin/python3.11 /usr/local/bin/python
python -V

apt install -y python3-venv
cd ..
python3.11 -m venv venv
ls
source /venv/bin/activate

pip3 install numpy opencv-python onnxruntime

git clone https://github.com/ultralytics/yolov5
cd yolov5
pip install -r requirements.txt 
wget https://github.com/ultralytics/yolov5/releases/download/v5.0/yolov5s.onnx

python detect.py --weights yolov5s.pt --source 0
python3 detect.py --weights yolov5s.onnx --img 640 --conf 0.5 --source 0






#########################