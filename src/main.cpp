
#include <opencv2/opencv.hpp>

#include "screenshot.h"

int main () {

  ScreenShot screen(0, 0, 1366, 768);

  cv::Mat img; 

  cv::namedWindow("img", cv::WINDOW_AUTOSIZE);

  screen(img);

  cv::imshow("img", img);
  cv::waitKey(0);

  
  return 0;

}

