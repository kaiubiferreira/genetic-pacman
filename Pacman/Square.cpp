#include "Square.h"

Square::Square(){}
Square::Square(Vector NW, Vector SW, Vector NE, Vector SE)
{
    this->NW = NW;
    this->SW = SW;
    this->NE = NE;
    this->SE = SE;
}

Square::Square(Vector startPosition, GLfloat size)
{
    this->NW = startPosition;
    this->NE = *new Vector(startPosition[0] + size, startPosition[1], startPosition[2]);
    this->SE = *new Vector(startPosition[0] + size, startPosition[1] - size, startPosition[2]);
    this->SW = *new Vector(startPosition[0], startPosition[1] - size, startPosition[2]);
}

Square::Square(Vector startPosition, GLfloat sizeX, GLfloat sizeY)
{
    this->NW = startPosition;
    this->NE = *new Vector(startPosition[0] + sizeX, startPosition[1], startPosition[2]);
    this->SE = *new Vector(startPosition[0] + sizeX, startPosition[1] - sizeY, startPosition[2]);
    this->SW = *new Vector(startPosition[0], startPosition[1] - sizeY, startPosition[2]);
}

void Square::drawSquareTexture(Texture textureSet, int textureIndex)
{
    glEnable(GL_TEXTURE_2D);
    textureSet.activate(textureIndex);

    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f);
            glVertex3f(this->NW[0], this->NW[1], this->NW[2]);

        glTexCoord2f(1.0f, 0.0f);
            glVertex3f(this->NE[0], this->NE[1], this->NE[2]);

        glTexCoord2f(1.0f, 1.0f);
            glVertex3f(this->SE[0], this->SE[1], this->SE[2]);

        glTexCoord2f(0.0f, 1.0f);
            glVertex3f(this->SW[0], this->SW[1], this->SW[2]);
    }
    glEnd();
}

void Square::rotate(GLfloat angle, Vector direction, GLfloat axisX, GLfloat axisY)
{
    axisX *= (this->NE[0] - this->NW[0]);
    axisX += this->NW[0];
    axisY *= (this->SW[1] - this->NW[1]);
    axisY += this->NW[1];

    Vector axis = *new Vector(axisX, axisY, this->NW[2]);

    glTranslatef(axis[0], axis[1], axis[2]);
    glRotatef(angle, direction[0], direction[1], direction[2]);
    delete &axis;
}

void Square::move(Vector newPosition)
{
    GLfloat sizeX, sizeY;
    sizeX = (this->NE - this->NW).getMagnitude();
    sizeY = (this->SW - this->NW).getMagnitude();

    this->NW.setCoordinates(newPosition[0], newPosition[1], newPosition[2]);
    this->NE.setCoordinates(newPosition[0] + sizeX, newPosition[1], newPosition[2]);
    this->SE.setCoordinates(newPosition[0] + sizeX, newPosition[1] - sizeY, newPosition[2]);
    this->SW.setCoordinates(newPosition[0], newPosition[1] - sizeY, newPosition[2]);
}

void Square::move(GLfloat unitsVetical, GLfloat untisHorizontal)
{
    Vector add = *new Vector(unitsVetical, untisHorizontal, 0);

    this->NW = this->NW + add;
    this->NE = this->NE + add;
    this->SE = this->SE + add;
    this->SW = this->SW + add;

    delete &add;
}

Vector Square::getNormal()
{
    return this->SE.getNormal(this->NW, this->SE);
}

Vector Square::getNW()
{
    return this->NW;
}

Vector Square::getSW()
{
    return this->SW;
}

Vector Square::getNE()
{
    return this->NE;
}

Vector Square::getSE()
{
    return this->SE;
}
