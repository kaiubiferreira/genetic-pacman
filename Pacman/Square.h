#include <GL/glut.h>
#include <GL/gl.h>
#include "Vector.h"
#include "Texture.h"


class Square
{
    private:
        Vector NW, SW, NE, SE;

    public:
        Square();
        Square(Vector NW, Vector SW, Vector NE, Vector SE);
        Square(Vector startPosition, GLfloat size);
        Square(Vector startPostition, GLfloat sizeX, GLfloat sizeY);
        ~Square()
        {
            //delete &NW;
            //delete &SW;
            //delete &NE;
            //delete &SE;
        }

        void drawSquareTexture(Texture textureSet, int textureIndex);

        void rotate(GLfloat angle, Vector direction, GLfloat axisY = 0.5f, GLfloat axisX = 1.0f);
        void move(Vector newPosition);
        void move(GLfloat unitsVetical, GLfloat untisHorizontal);

        Vector getNormal();
        Vector getNW();
        Vector getSW();
        Vector getNE();
        Vector getSE();
};
