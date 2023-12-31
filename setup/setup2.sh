#set up yolov5

git clone https://github.com/ultralytics/yolov5
cd yolov5

#can go in env 
pip install -r requirements.txt 


# try use
python detect.py --weights yolov5s.pt --source 0
python detect.py --weights yolov5s.pt --source 0 --conf 0.8
# train 
python train.py --img 640 --epochs 3 --data coco128.yaml --weights yolov5s.pt
# python train.py --data coco.yaml --epochs 300 --weights '' --cfg yolov5n.yaml  --batch-size 128



#train using gpu
pip3 install torch==1.10.0+cu113 torchvision==0.11.1+cu113 torchaudio===0.10.0+cu113 -f https://download.pytorch.org/whl/cu113/torch_stable.html
pip install torch torchvision torchaudio numpy opencv-python pandas matplotlib PyYAML tensorboard seaborn psutil

####cu important
pip install torch==2.0.0+cu117 torchvision==0.15.1+cu117 torchaudio==2.0.1 --index-url https://download.pytorch.org/whl/cu117
####fix this problem ###################
#https://gist.github.com/cobryan05/7d1fe28dd370e110a372c4d268dcb2e5
# oserror: [winerror 1455] the paging file is too small for this operation to complete. error loading c:\users\user\appdata\local\programs\python\python39\lib\site-packages\torch\lib\caffe2_detectron_ops_gpu.dll or one of its dependencies.
###################################

pip install pefile
#need create a file call fixNvpe.py
# python fixNvPe.py --input C:\Users\Admin\anaconda3\envs\newyolo\lib\site-packages\torch\lib\*.dll
# c:\users\user\appdata\local\programs\python\python39\lib\site-packages\torch\lib\*.dll
python fixNvPe.py --input c:\users\user\appdata\local\programs\python\python39\lib\site-packages\torch\lib\*.dll

python train.py --img 640 --batch 16 --epochs 100 --data coco128.yaml --weights yolov5s.pt --device 0
python train.py --img 640 --batch 8 --epochs 2 --data coco128.yaml --weights yolov5s.pt 
python train.py --img 640 --epochs 2 --data coco128.yaml --weights yolov5s.pt 

# exp1
python train.py --img 640 --batch 16 --epochs 100 --data data/data.yaml --weights yolov5s.pt --device 0
# exp2
python train.py --img 640 --batch 8 --epochs 100 --data data/data.yaml --weights yolov5s.pt --device 0
# exp3
python train.py --img 640 --batch 8 --epochs 300 --data data/data.yaml --weights yolov5s.pt --device 0
# exp4
python train.py --img 640 --batch 16 --epochs 300 --data data/data.yaml --weights yolov5s.pt --device 0
# exp5
python train.py --img 640 --batch 8 --epochs 500 --data data/data.yaml --weights yolov5s.pt --device 0
# exp6
python train.py --img 640 --batch 16 --epochs 500 --data data/data.yaml --weights yolov5s.pt --device 0
# exp7
python train.py --img 640 --batch 8 --epochs 800 --data data/data.yaml --weights yolov5s.pt --device 0
# exp8
# python train.py --img 640 --batch 16 --epochs 800 --data data/data.yaml --weights yolov5s.pt --device 0
# # exp9
# python train.py --img 640 --batch 8 --epochs 1000 --data data/data.yaml --weights yolov5s.pt --device 0
# # exp10
# python train.py --img 640 --batch 16 --epochs 1000 --data data/data.yaml --weights yolov5s.pt --device 0

python .\detect.py --source 0 --weights .\runs\train\exp15\weights\best.pt