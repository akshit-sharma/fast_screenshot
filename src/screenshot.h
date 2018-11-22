#pragma once

#if defined(__linux__)
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#else
#endif

#include <opencv2/opencv.hpp>

class ScreenShot {

  private:
#if defined(__linux__)
    Display *display;
    Window root;
    XImage *img;
#else

#endif
 
    int x, y, width, height;
    bool init;

    ScreenShot();

  public:

    ScreenShot(int x, int y, int width, int height);
    void operator() (cv::Mat &cvImg);
    ~ScreenShot();

};

