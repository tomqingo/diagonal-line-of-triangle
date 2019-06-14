#include <iostream>
#include <vector>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <cmath>

using namespace cv;

int main(){
    Mat MyImage=imread("/home/tomqin/normal/triangle_real.jpg"); //参数为你导入图片具体所在路径
    namedWindow("INPUT",2);
    namedWindow("OUTPUT",2);
    if(!MyImage.data){
        cout<<"读取不到图片"<<endl;
        return 0;
    }
                                                                         //读取图片
     /*
    图像处理算法
    */
    imshow("INPUT", MyImage);
    imshow("OUTPUT",drawing); //输入图片和输出图片显示
    waitKey(0);
    return 1;
}
