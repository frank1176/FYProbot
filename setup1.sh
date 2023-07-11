#setup cvat windows
# https://www.youtube.com/watch?v=hyvNFuc06qQ&t=218s&ab_channel=CVAT

#install docker
# https://www.docker.com/

#check docker version
docker --version


# install cvat
# https://opencv.github.io/cvat/docs/administration/basics/installation/
cd ..
git clone https://github.com/opencv/cvat
cd cvat

cd ~
cd Desktop/sem6_v2/FYP/cvat
/sem6_v2/FYP/cvat
docker compose up -d

docker ps
docker logs cvat_server -f
docker exec -it cvat_server bash -ic 'python3 ~/manage.py createsuperuser'

# super user
#engineer
#AnakPerantau

# stop docker
docker-compose down