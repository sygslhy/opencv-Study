#include "opencv2/highgui/highgui.hpp"
using namespace cv;
#include "iostream"
using namespace std;

#define STATS_WIDTH  32
#define STATS_HEIGHT 32
uchar Blue[512*512];
uchar Green[512*512];
uchar Red[512*512];

int main(int argc, char **argv){
    Mat img = imread("lena.jpg");
    Mat B = img.clone();
    Mat C(img,  Rect(10, 10, 100, 100) );
    //namedWindow("image", WINDOW_AUTOSIZE);
    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    cout << "M = " << endl << " " << M << endl << endl;
    M.create(4,4, CV_8UC(2));
    cout << "M = "<< endl << " "  << M << endl << endl;
    Mat E = Mat::eye(4, 4, CV_64F);
    cout << "E = " << endl << " " << E << endl << endl;
    Mat O = Mat::ones(2, 2, CV_32F);
    cout << "O = " << endl << " " << O << endl << endl;
    Mat Z = Mat::zeros(3,3, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl << endl;
    //waitKey();
    return 0;
}

