/*
 程序功能：利用OpenCV对图像进行批处理
 
 使用步骤：
 1.首先将输入图像的名称统一改成 0001-9999（Mac可以使用系统自带的重命名中的 格式 进行修改）
 2.其次在程序中修改输入图像的路径
 3.在程序中修改输入图像的数量
 4.在程序中需要的地方（输入和输出）修改输入图像的类型
 5.将需要对每张图像进行的操作拷贝至handle函数中（在main函数后面）
 
 作者：虹麟君
 2021.01.21
 */

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

char * luJing = "/Users/lhl/Desktop/";//输入图像路径
const int imageNumber = 9;//输入图像的数量

Mat handle(Mat src);

int main()
{

    char filename[256];
    for (int i = 1; i < imageNumber; i++)
    {
        if (i < 10)
            sprintf(filename, "%s000%d.png", luJing, i);//此处修改输入图像的文件类型
        if (i >= 10 && i < 100)
            sprintf(filename, "%s00%d.pgm",luJing, i);
        if (i >= 100)
            sprintf(filename, "%s0%d.pgm", luJing, i);
        if (i >= 1000)
            sprintf(filename, "%s%d.pgm", luJing, i);
            
        Mat src = imread(filename);//读取图像
        
        handle(src);//处理图像
        
        if (!src.data)
        {
            printf("the image could not be loaded...\n");
            printf("filename is : %s\n", filename);
            return 0;
        }

        sprintf(filename, "%s%d.png", luJing, i);//此处修改输出图像的格式
        imwrite(filename, src);//输出图像
    }
    waitKey(0);
    return 0;
}


Mat handle(Mat src){
    

}
