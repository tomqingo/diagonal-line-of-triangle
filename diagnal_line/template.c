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
    Mat MyImage=imread("/home/tomqin/normal/triangle_real.jpg"); //����Ϊ�㵼��ͼƬ��������·��
    namedWindow("INPUT",2);
    namedWindow("OUTPUT",2);
    if(!MyImage.data){
        cout<<"��ȡ����ͼƬ"<<endl;
        return 0;
    }
                                                                         //��ȡͼƬ
     /*
    ͼ�����㷨
    */
    imshow("INPUT", MyImage);
    imshow("OUTPUT",drawing); //����ͼƬ�����ͼƬ��ʾ
    waitKey(0);
    return 1;
}
