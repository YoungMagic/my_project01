批量解压
for i in `ls *.tar`
do
mkdir ./${i/.tar//}
tar xvf $i -C ${i/.tar//}
done

批量替换
$files=Get-Childitem /home/mq/data/VOCdevkit/mydataset/Annotations *.xml
foreach($file in $files)
{
 $content=get-content $file.pspath
 clear-content $file.pspath
  foreach($line in $content)
   {
    $liner = $line.Replace(".0","")
    Add-content $file.pspath-Value $liner
   }
}


windows powershell下运行
$files=Get-Childitem /home/mq/data/test *.xml
foreach($file in $files)
{
 $content=get-content $file.pspath
 clear-content $file.pspath
  foreach($line in $content)
   {
    $liner = $line.Replace(".0","")
    Add-content $file.pspath-Value $liner
   }
}


SSD训练步骤
http://blog.csdn.net/zhang_shuai12/article/details/52346878
其中修改8行create_data.sh，改为dataset_name="mydataset" 
修改create_list.sh，13行，改为for name in mydataset


HDF5问题
Export PYTHONPATH=/opt/ssd/caffe/python
export PYTHONPATH=/opt/SSD/caffe/python:$PYTHONPATH
export PYTHONPATH=/usr/lib/python2.7/dist-packages:/opt/ssd/caffe/python
makefile 修改 
INCLUDE_DIRS :=  $(PYTHON_INCLUDE) /usr/local/include /usr/include/hdf5/serial
LIBRARY_DIRS := $(PYTHON_LIB) /usr/local/lib /usr/lib /usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/hdf5/serial

命令| tee xxx.txt

#修改xml文件的内容
$files=Get-Childitem /home/mq/data/VOCdevkit/mydataset/Annotations *.xml
foreach($file in $files)
{
 $content=get-content $file.pspath
 clear-content $file.pspath
  foreach($line in $content)
   {
    $liner = $line.Replace(".0","")
    Add-content $file.pspath-Value $liner
   }
}

提高学习率
resnet101作为前置网络


http://blog.csdn.net/liukang325/article/details/46237067 ffmpeg 解码RTS
https://github.com/weiliu89/caffe/tree/ssd
http://blog.csdn.net/zhang_shuai12/article/details/52554604论文梳理

裁剪图片
#include <iostream>
#include <fstream>
#include <stdlib.h> //srand()和rand()函数
#include <time.h> //time()函数
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/ml/ml.hpp>

using namespace std;
using namespace cv;

int CropImageCount = 0; //裁剪出来的负样本图片个数

int main()
{
	Mat src;
	string ImgName;
	char saveName[256];//裁剪出来的负样本图片文件名
	ifstream fin("INRIANegativeImageList.txt");//打开原始负样本图片文件列表
	//ifstream fin("subset.txt");

	//一行一行读取文件列表
	while(getline(fin,ImgName))
	{
		cout<<"处理："<<ImgName<<endl;
		ImgName = "D:\\DataSet\\INRIAPerson\\INRIAPerson\\Train\\neg\\" + ImgName;
		src = imread(ImgName);//读取图片
		//cout<<"宽："<<src.cols<<"，高："<<src.rows<<endl;

		//图片大小应该能能至少包含一个64*128的窗口
		if(src.cols >= 64 && src.rows >= 128)
		{
			srand(time(NULL));//设置随机数种子

			//从每张图片中随机裁剪10个64*128大小的不包含人的负样本
			for(int i=0; i<10; i++)
			{
				int x = ( rand() % (src.cols-64) ); //左上角x坐标
				int y = ( rand() % (src.rows-128) ); //左上角y坐标
				//cout<<x<<","<<y<<endl;
				Mat imgROI = src(Rect(x,y,64,128)); 
				sprintf(saveName,"noperson%06d.jpg",++CropImageCount);//生成裁剪出的负样本图片的文件名
				imwrite(saveName, imgROI);//保存文件
			}
		}
	}

	system("pause");
}
