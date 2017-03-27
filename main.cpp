#include	<opencv2/opencv.hpp>
#include	<iostream>
using	namespace	std;
using	namespace	cv;
int	main(int,	char	*argv[])
{
    Mat img = imread("lena.jpg", IMREAD_GRAYSCALE);
    uchar pix1 = img.at<uchar>(0,0);
    cout << " pixel is " << (unsigned int)pix1 << " at (0,0) " << endl;

    Mat imgrgb = imread("lena.jpg", IMREAD_COLOR);
    Vec3b pix2 = imgrgb.at<Vec3b>(0,0);
    cout << " pixel B is " << (unsigned int)pix2[0] << " at (0,0) " << endl;
    cout << " pixel G is " << (unsigned int)pix2[1] << " at (0,0) " << endl;
    cout << " pixel R is " << (unsigned int)pix2[2] << " at (0,0) " << endl;

    cout << " image size = " << imgrgb.size().height *imgrgb.size().width << endl;
    for(int i=0; i<imgrgb.rows; i++){
        Vec3b *ptr = imgrgb.ptr<Vec3b>(i);
        for(int j=0; j<imgrgb.cols; j++){
            uchar B = ptr[j][0];
            uchar G = ptr[j][1];
            uchar R = ptr[j][2];
        }
    }

    return	0;
}
