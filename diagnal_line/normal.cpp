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
    /*
    const int MAX_CORNERS = 3;
    vector<Point2f> corners;
    vector< vector<Point> > contours;
    vector< Vec4i > hierarchy;
    Mat channels[3];
    int corner_count = MAX_CORNERS;
    int half_win_size = 100;
    int iteration = 40;
    double epislon = 0.001;
    double qualityLevel = 0.01;
    double minDistance = 3;
    int blockSize = 3;
    bool useHarrisDetector = false;
    double k = 0.04;
    double x1=0, y1=0;
    double x2=0, y2=0;
    double finalx=0, finaly=0;
    Mat img_out;
    */
    /*
    参数定义
    */
    if(!MyImage.data){
        cout<<"读取不到图片"<<endl;
        return 0;
    }
    /*                                                                     //读取图片
    Mat red;
    Mat green;
    Mat blue;
    split(MyImage, channels);
    blue= channels[0];
    green= channels[1];
    red= channels[2];
    img_out.create(MyImage.rows, MyImage.cols, CV_8UC1);
    for (int j = 1; j < blue.rows - 1; j++)
        {
            uchar* currentblue = blue.ptr< uchar>(j);
            uchar* currentgreen = green.ptr< uchar>(j);
            uchar* currentred = red.ptr< uchar>(j);
            uchar* current = img_out.ptr< uchar>(j);
            for (int i = 1; i < blue.cols - 1; i++)
            {
                if ((currentred[i] <= 255) && (currentred[i] >=140) && (currentblue[i] <= 60) && (currentgreen[i] <= 60))
                    current[i] = 255;

                else
                    current[i] = 0;
            }
        }
    //RGB颜色空间阈值分割提取红色区域
    Mat element= getStructuringElement(MORPH_RECT, Size(1,1));
    erode(img_out, img_out, element);
    dilate(img_out, img_out, element);
    medianBlur(img_out, img_out, 33);
    //形态学处理以及中值滤波，消除边缘毛刺
    findContours(img_out, contours, hierarchy, CV_RETR_EXTERNAL,  CV_CHAIN_APPROX_SIMPLE);
    Mat drawing = Mat::zeros( img_out.size(), CV_8UC1 );
    for( int i = 0; i< contours.size(); i++ )
         {
           cv::drawContours( drawing, contours, i, Scalar(255,255,255), 4, 8, vector<Vec4i>(), 0, Point() );
          }
    //提取绘制轮廓。
    Mat copy;
    copy = drawing.clone();
    goodFeaturesToTrack( copy, corners, MAX_CORNERS, qualityLevel, minDistance, Mat(), blockSize, useHarrisDetector, k );
    cout<<"** Number of corners detected: "<<corners.size()<<endl;
    int r = 4;
    for( int i = 0; i < 3; i++ )
     { circle( MyImage, corners[i], r, Scalar(255, 0, 0), -1, 8, 0 ); }

    cornerSubPix(copy, corners, Size(half_win_size, half_win_size), Size(-1,-1), TermCriteria(CV_TERMCRIT_ITER+CV_TERMCRIT_EPS,iteration,epislon) );
    for(int i=0; i < corners.size(); i++)
    {cout<<corners[i].x<<' '<<corners[i].y<<endl;}
    //利用Shi-Tomasi方法（goodFeaturesToTrack和cornerSubPix函数）进行亚像素级角点检测，找到三角形三个顶点
    x1 = (corners[0].x-corners[2].x)/(sqrt(pow((corners[0].x-corners[2].x),2)+pow((corners[0].y-corners[2].y),2)));
    y1 = (corners[0].y-corners[2].y)/(sqrt(pow((corners[0].x-corners[2].x),2)+pow((corners[0].y-corners[2].y),2)));
    x2 = (corners[1].x-corners[2].x)/(sqrt(pow((corners[1].x-corners[2].x),2)+pow((corners[1].y-corners[2].y),2)));
    y2 = (corners[1].y-corners[2].y)/(sqrt(pow((corners[1].x-corners[2].x),2)+pow((corners[1].y-corners[2].y),2)));
    finalx = (x1 + x2)/(sqrt(pow((x1 + x2),2)+pow((y1 + y2),2)));
    finaly = (y1 + y2)/(sqrt(pow((x1 + x2),2)+pow((y1 + y2),2)));
    cout<<"x:"<<finalx<<' '<<"y:"<<finaly<<endl;
    Point dst((1000*finalx+corners[2].x), (1000*finaly+corners[2].y));
    line(MyImage, corners[2] , dst , Scalar(255,0,0), 1, 8, 0);
    //利用高中方法求取两条边单位向量，求取直角平分线所在方向向量
    */
    /*
    图像处理算法
    */
    imshow("INPUT", MyImage);
    imshow("OUTPUT",drawing); //输入图片和输出图片显示
    waitKey(0);
    return 1;
}
