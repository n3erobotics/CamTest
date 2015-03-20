#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono ;

int main(int argc, char* argv[])
{
    int camera = atoi(argv[1]);
    cout << "Trying camera " << camera << endl;
    VideoCapture cap(camera); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
        Mat frame;

	auto begin = high_resolution_clock::now() ;
        bool bSuccess = cap.read(frame); // read a new frame from video  
        auto end = high_resolution_clock::now() ;
	auto ticks = duration_cast<microseconds>(end-begin) ;

	std::cout << "It took me " << ticks.count()/1000 << " ms.\n" ;

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }
    return 0;

}
