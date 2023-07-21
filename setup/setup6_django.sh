# Activate the virtual environment
pip install django
pip install djangorestframework
pip install django-rest-knox 
pip install --upgrade pip


python -m django --version
django-admin startproject backend_robot
cd backend_robot 
pip install djangorestframework django-rest-knox django-cors-headers daphne channels channels-redis
python manage.py runserver
python manage.py makemigrations
python manage.py migrate
python manage.py showmigrations

python manage.py startapp test_app


# daphne -e ssl:8000:privateKey=/etc/nginx/ssl/kynoci.com-sub-privkey.pem:certKey=/etc/nginx/ssl/kynoci.com-sub-cert.pem backend_robot.asgi:application
daphne -e ssl:8000:privateKey=/kynoci.com-sub-privkey.pem:certKey=/kynoci.com-sub-cert.pem backend_robot.asgi:application

