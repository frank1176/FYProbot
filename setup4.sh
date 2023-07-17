################
# aiortc (python)
sudo su -
apt -y install python3 python3-pip libgl1
exit
cd ~
git clone git@github.com:aiortc/aiortc.git

pip install opencv-python aiohttp aiortc
cd aiortc/examples/server/
python server.py
################