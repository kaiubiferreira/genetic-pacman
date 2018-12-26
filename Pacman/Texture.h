#include "Image.h"
#include <GL/glut.h>

class Texture
{
    private:
            GLuint * id;
            int quantity;
    public:
            Texture();
            Texture(const char ** filenames, int quantity);
            void activate(GLuint index);
            GLuint getId();
};

