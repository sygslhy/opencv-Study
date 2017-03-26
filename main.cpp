#include	<opencv2/opencv.hpp>
#include	<iostream>
using	namespace	std;
using	namespace	cv;
int	main(int,	char	*argv[])
{
    Mat in_frame, out_frame;
    const char win1[] = "Grabbing", win2[] = "Recording";
    double fps = 30;
    char file_out[] = "record.avi";
    VideoCapture inVid(0);
    if (!inVid.isOpened()){
        cout << "Error, Camera is not ready" << endl;
        return -1;
    }

    int width = (int)inVid.get(CAP_PROP_FRAME_WIDTH);
    int height = (int)inVid.get(CAP_PROP_FRAME_HEIGHT);

    cout << "witdh = " << width << " height = " << height << endl;

    VideoWriter recVid(file_out,
    VideoWriter::fourcc('M','P','E','G'),
    fps, Size(width, height));

    if (!recVid.isOpened()) {
        cout << "Error! Video file not opened...\n";
        return -1;
    }

    namedWindow(win1);
    namedWindow(win2);

    while (true) {
        // Read frame from camera (grabbing and decoding)
        inVid >> in_frame;
        // Convert the frame to grayscale
        cvtColor(in_frame, out_frame, COLOR_BGR2GRAY);
        // Write frame to video file (encoding and saving)
        recVid << out_frame;
        imshow(win1, in_frame); // Show frame in window
        imshow(win2, out_frame); // Show frame in window
        if (waitKey(1000/fps) >= 0)
        break;
    }
    inVid.release();

    return	0;
}
