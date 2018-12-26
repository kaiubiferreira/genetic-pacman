#include "Texture.h"

Texture::Texture(){}
Texture::Texture(const char ** filenames, int quantity)
{
    Image * image = new Image[quantity];

    this->id = (GLuint*)malloc(sizeof(GLuint)* quantity);
    this->quantity = quantity;
    glGenTextures(quantity, this->id);

    for(int i = 0; i < quantity; i++)
    {
        image[i] = * new Image(filenames[i]);

        glBindTexture(GL_TEXTURE_2D, this->id[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                     image[i].getWidth(),
                     image[i].getLength(),
                     0, GL_RGB, GL_UNSIGNED_BYTE,
                     image[i].getImage());

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    delete[] image;
}

void Texture::activate(GLuint textId)
{
    glBindTexture(GL_TEXTURE_2D, this->id[textId]);
}

GLuint Texture::getId()
{
    return this->id[0];
}

