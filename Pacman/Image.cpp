#include "image.h"

Image::Image(){}

Image::Image(const char * fileName)
{
    loadImage(fileName);
}

void Image::loadImage(const char * fileName)
{
    unsigned char * pixelsArray;
    pixelsArray = SOIL_load_image(fileName, &(this->width), &(this->length), 0, SOIL_LOAD_RGB);
    if(pixelsArray != NULL)
    {
        this->pixels = pixelsArray;
    }
    else
    {
        cout << endl << "Exeption: Image file " << fileName << " not found" << endl;
    }
}

unsigned char * Image::getImage()
{
    return this->pixels;
}

int Image::getWidth()
{
    return this->width;
}

int Image::getLength()
{
    return this->length;
}
