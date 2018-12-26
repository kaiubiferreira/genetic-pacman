#include "enable.h"

void Settings::resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void Settings::setWindowsSize(int width, int height)
{
    this->windowsWidth = width;
    this->windowsHeight = height;
    glutReshapeWindow(width, height);
}

void Settings::setTitle(const char * title)
{
    this->title = title;
    glutSetWindowTitle(title);
}

void Settings::setBackgroundColor()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1);
}
