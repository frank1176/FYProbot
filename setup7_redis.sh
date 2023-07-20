
# WSL terminal  windows's debian 

sudo su -
apt-get update
apt-get install redis
service redis-server start
redis-cli



######SSL###############
curl -O -k "https://getcert:zdf76tde7bg7bfs@103.68.63.123/ssl/kynoci.com-sub-privkey.pem"
curl -O -k "https://getcert:zdf76tde7bg7bfs@103.68.63.123/ssl/kynoci.com-sub-cert.pem"