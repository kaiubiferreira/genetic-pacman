#include <SOIL.h>
#include <stdlib.h>
#include <iostream>
#include "GL/gl.h"

using namespace std;

class Image
{
    private:
        int width, length;
        unsigned char * pixels;

    public:
        Image();
        Image(const char *);
        ~Image()
        {
            delete[] pixels;
        }

        void loadImage(const char *);
        unsigned char * getImage();
        int getWidth();
        int getLength();
};
