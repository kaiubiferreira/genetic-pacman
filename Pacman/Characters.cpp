#include "Characters.h"


void Characters::calculateRelativePositions()
{
    this->relativeX = (this->actualX - this->scenarioStartPositionX)/(this->cellSize);
    this->relativeY = (this->actualY - this->scenarioStartPositionY)/(this->cellSize);
}

void Characters::correctPosition()
{
    this->actualX = scenarioStartPositionX  + this->cellSize/2 + (cellSize * this->relativeX);
    this->actualY = scenarioStartPositionY  + cellSize * (this->relativeY + 0.5);
}

void Characters::setDirection(int direction)
{
    this->direction = direction;
}

int Characters::getDirection()
{
    return this->direction;
}

int Characters::getRelativeX()
{
    return this->relativeX;
}

int Characters::getRelativeY()
{
    return this->relativeY;
}

void Characters::setRelativeXY(int x, int y)
{
    this->relativeX = x;
    this->relativeY = y;
    correctPosition();
}

void Characters::moveCharacter(float pace)
{
    switch(this->direction)
    {
        case 0: this->actualY += pace;
            break;
        case 1: this->actualX += pace;
            break;
        case 2: this->actualY -= pace;
            break;
        case 3: this->actualX -= pace;
            break;
    }

    calculateRelativePositions();
}

void Characters::drawCharacter()
{
    Vector cellVec = * new Vector(actualX - cellSize/2, actualY + cellSize/2, 0);
    Square cellCharacter = * new Square(cellVec, 0.2);
    glPushMatrix();
        cellCharacter.drawSquareTexture(textureSet, currentSprite);
    glPopMatrix();

    delete[] &cellVec;
    delete[] &cellCharacter;
    glutPostRedisplay();
}

void Characters::setNextDirection(int nextDirection, bool allowReverse)
{
    if(allowReverse)
    {
        this->nextDirection = nextDirection;
    }
    else
    {
         switch(this->nextDirection)
        {
            case 0: if(nextDirection != 2)
                        this->nextDirection = nextDirection;
                break;
            case 1:
                    if(nextDirection != 3)
                        this->nextDirection = nextDirection;
                break;
            case 2:
                    if(nextDirection != 0)
                        this->nextDirection = nextDirection;
                break;
            case 3: if(nextDirection != 1)
                        this->nextDirection = nextDirection;
                break;
        }
    }
}

int Characters::getNextDirection()
{
    return this->nextDirection;
}

