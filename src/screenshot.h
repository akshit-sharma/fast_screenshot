#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <opencv2/opencv.hpp>

class ScreenShot {

  private:
    Display *display;
    Window root;
    int x, y, width, height;
    XImage *img;
 
    bool init;

    ScreenShot();

  public:

    ScreenShot(int x, int y, int width, int height);
    void operator() (cv::Mat &cvImg);
    ~ScreenShot();

};

