
#include "screenshot.h"

#include <iostream>

ScreenShot::ScreenShot() :
  init(true)
{
#if defined(__linux__)
  display = XOpenDisplay(nullptr);
  if (!display) {
    std::cout << "display is null\n";
    exit(1);
  }
  root = DefaultRootWindow(display);
  if (!root) {
    std::cout << "root is null\n";
    exit(1);
  }
#else

#endif // __linux__

}

ScreenShot::ScreenShot(int x, int y, int width, int height) : 
  x(x), y(y), width(width), height(height), init(true)
{
#if defined(__linux__)
  display = XOpenDisplay(nullptr);
  if (!display) {
    std::cout << "display is null\n";
    exit(1);
  }
  root = DefaultRootWindow(display);
  if (!root) {
    std::cout << "root is null\n";
    exit(1);
  }
#else

#endif // __linux__
}

ScreenShot::~ScreenShot() 
{
#if defined(__linux__)
  if (!init)  // init == false
    XDestroyImage(img);

  XCloseDisplay(display);
#else

#endif // __linux__
}

void ScreenShot::operator() (cv::Mat &cvImg) 
{
#if defined(__linux__)
  if (!init) {
    XDestroyImage(img);
  }

  init = (init == true) ? false : init;

  img = XGetImage(display, root, x, y, width, height, AllPlanes, ZPixmap);

  cvImg = cv::Mat(height, width, CV_8UC4, img->data); 
#else
  cvImg = cv::Mat(height, width, CV_8UC4, cv::Scalar(5, 10, 15, 20));
#endif // __linux__
}

