
# WSL terminal  windows's debian 

sudo su -
apt-get update
apt-get install redis
service redis-server start
redis-cli