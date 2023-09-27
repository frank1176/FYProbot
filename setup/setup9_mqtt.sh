pip install pika 

cat > /etc/apt/sources.list << EOF
deb http://ftp.jp.debian.org/debian/ bullseye main contrib non-free
deb http://ftp.jp.debian.org/debian/ bullseye-updates main contrib non-free
EOF
apt -y update && apt -y dist-upgrade

### Step 2 : Install Tools
apt -y install curl gnupg apt-transport-https

### Step 3 : Install Erlang
apt -y install curl wget
apt-cache policy erlang
curl -1sLf "https://packagecloud.io/rabbitmq/rabbitmq-server/gpgkey" | gpg --dearmor | tee /usr/share/keyrings/io.packagecloud.rabbitmq.gpg > /dev/null
wget https://packages.erlang-solutions.com/erlang-solutions_2.0_all.deb
apt install ./erlang-solutions_2.0_all.deb
apt -y update
apt-cache policy erlang
apt install -y erlang-base erlang-asn1 erlang-crypto erlang-eldap erlang-ftp \
    erlang-inets erlang-mnesia erlang-os-mon erlang-parsetools \
    erlang-public-key erlang-runtime-tools erlang-snmp erlang-ssl \
    erlang-syntax-tools erlang-tftp erlang-tools erlang-xmerl
apt-cache policy erlang
# erl --version

### Step 4 : Install RabbitMQ
apt-cache policy rabbitmq-server
tee /etc/apt/sources.list.d/rabbitmq.list <<EOF
deb [signed-by=/usr/share/keyrings/io.packagecloud.rabbitmq.gpg] https://packagecloud.io/rabbitmq/rabbitmq-server/debian/ bullseye main
deb-src [signed-by=/usr/share/keyrings/io.packagecloud.rabbitmq.gpg] https://packagecloud.io/rabbitmq/rabbitmq-server/debian/ bullseye main
EOF
apt -y update
apt-cache policy rabbitmq-server
apt install rabbitmq-server -y --fix-missing
service rabbitmq-server restart



rabbitmq-plugins enable rabbitmq_management
rabbitmqctl add_user engineer anakperantau
rabbitmqctl set_user_tags engineer administrator
rabbitmqctl set_permissions -p / engineer ".*" ".*" ".*"
rabbitmqctl "report"

### Step 12 : Enable User Account
rabbitmqctl add_user babi chu
rabbitmqctl set_permissions -p / babi ".*" ".*" ".*"
rabbitmqctl set_user_tags babi management