#include "screenshot.h"

ScreenShot::ScreenShot() :
  init(true)
{

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

}

ScreenShot::ScreenShot(int x, int y, int width, int height) : 
  x(x), y(y), width(width), height(height)
{
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
  init = true;
  // ScreenShot();
}

ScreenShot::~ScreenShot() 
{
  if (!init)  // init == false
    XDestroyImage(img);

  XCloseDisplay(display);
}

void ScreenShot::operator() (cv::Mat &cvImg) 
{
  if (!init) {
    XDestroyImage(img);
    // init = true;
  }

  init = (init == true) ? false : init;

  img = XGetImage(display, root, x, y, width, height, AllPlanes, ZPixmap);

  cvImg = cv::Mat(height, width, CV_8UC4, img->data); 
}

