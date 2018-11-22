
#include <opencv2/opencv.hpp>

#include <chrono>

#include "screenshot.h"

int main () {

  ScreenShot screen(100, 100, 1366, 768);

  cv::Mat img; 

  cv::namedWindow("img", cv::WINDOW_AUTOSIZE);

  int key, frames = 0, deltaTime = 0, micro2sec = 1000 * 1000;
  std::chrono::high_resolution_clock::time_point t1, t2;

  while(true) {

    if (key == 'q') break;

    t1 = std::chrono::high_resolution_clock::now();
  
    screen(img);

    cv::imshow("img", img);
    key = cv::waitKey(1);

    t2 = std::chrono::high_resolution_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    
    deltaTime += diff;
    frames++;

    if (deltaTime > 1000 * 1000) { // every second
      double fps = static_cast<double>(frames);
      deltaTime -= micro2sec;
      frames = 0;
      std::cout << "fps : " << fps << "\n";
    }

  }
  
  return 0;

}

