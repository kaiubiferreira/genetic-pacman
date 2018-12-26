#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include "Characters.h"

using namespace std;

class Settings
{
    private:
        GLuint windowsWidth;
        GLuint windowsHeight;
        GLuint windowsPositionX;
        GLuint windowsPositionY;
        const char * title;

    public:
        Settings(){}

        Settings(void (GLUTCALLBACK * func)(void), const char * title = "Untitled", int windowsWidth = 640, int windowsHeight = 480, int windowsPositionX = 0, int windowsPositionY = 0)
        {
            this->windowsWidth = windowsWidth;
            this->windowsHeight = windowsHeight;
            this->windowsPositionX = windowsPositionX;
            this->windowsPositionY = windowsPositionY;
            this->title = title;

            glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

            glutInitWindowSize(windowsWidth, windowsHeight);
            glutInitWindowPosition(windowsPositionX,windowsPositionY);
            glutCreateWindow(title);

            glEnable(GL_COLOR_MATERIAL);
            glEnable(GL_TEXTURE_2D);

            setBackgroundColor();

            glutReshapeFunc(resize);
            glutDisplayFunc(func);
        }

        void setBackgroundColor();

        void setWindowsSize(int width, int height);

        void setTitle(const char * title);

        static void resize(int width, int height);
        static void key(unsigned char key, int x, int y);
};
