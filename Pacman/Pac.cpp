#include "Characters.h"

Pac::Pac(int pacStartPositionX, int pacStartPositionY, Scenario scenario)
{
    this->direction = 3;
    this->nextDirection = 3;
    this->cellSize = scenario.getCellSize();
    this->textureSet = scenario.getTextureSet();
    this->scenarioStartPositionX = scenario.getStartPositionX();
    this->scenarioStartPositionY = scenario.getStartPositionY() - scenario.getCellSize();
    this->currentSprite = PACLEFT1;

    this->relativeX = pacStartPositionX;
    this->relativeY = pacStartPositionY;

    correctPosition();
}

void Pac::updateCurrentSprite()
{
    switch(direction)
    {
        case 0:
                switch(this->currentSprite)
                {
                    case PACUP1:  this->currentSprite = PACUP2;
                                    mouth = 1;
                        break;
                    case PACUP2:  if(mouth == 1)
                                        this->currentSprite = PACUP3;
                                    else
                                        this->currentSprite = PACUP1;
                        break;
                    case PACUP3:  if(mouth == 1)
                                        this->currentSprite = PACUP4;
                                    else
                                        this->currentSprite = PACUP2;
                        break;
                    case PACUP4:  if(mouth == 1)
                                        this->currentSprite = PACUP5;
                                    else
                                        this->currentSprite = PACUP3;
                        break;
                    case PACUP5:  this->currentSprite = PACUP4;
                                    mouth = -1;
                        break;
                    default: this->currentSprite = PACUP1;
                        break;
                }
            break;
        case 1:
                switch(this->currentSprite)
                {
                    case PACRIGHT1:  this->currentSprite = PACRIGHT2;
                                    mouth = 1;
                        break;
                    case PACRIGHT2:  if(mouth == 1)
                                        this->currentSprite = PACRIGHT3;
                                    else
                                        this->currentSprite = PACRIGHT1;
                        break;
                    case PACRIGHT3:  if(mouth == 1)
                                        this->currentSprite = PACRIGHT4;
                                    else
                                        this->currentSprite = PACRIGHT2;
                        break;
                    case PACRIGHT4:  if(mouth == 1)
                                        this->currentSprite = PACRIGHT5;
                                    else
                                        this->currentSprite = PACRIGHT3;
                        break;
                    case PACRIGHT5:  this->currentSprite = PACRIGHT4;
                                    mouth = -1;
                        break;
                    default: this->currentSprite = PACRIGHT1;
                        break;
                }
            break;
        case 2:
                switch(this->currentSprite)
                {
                    case PACDOWN1:  this->currentSprite = PACDOWN2;
                                    mouth = 1;
                        break;
                    case PACDOWN2:  if(mouth == 1)
                                        this->currentSprite = PACDOWN3;
                                    else
                                        this->currentSprite = PACDOWN1;
                        break;
                    case PACDOWN3:  if(mouth == 1)
                                        this->currentSprite = PACDOWN4;
                                    else
                                        this->currentSprite = PACDOWN2;
                        break;
                    case PACDOWN4:  if(mouth == 1)
                                        this->currentSprite = PACDOWN5;
                                    else
                                        this->currentSprite = PACDOWN3;
                        break;
                    case PACDOWN5:  this->currentSprite = PACDOWN4;
                                    mouth = -1;
                        break;
                    default: this->currentSprite = PACDOWN1;
                        break;
                }
            break;
        case 3:
                switch(this->currentSprite)
                {
                    case PACLEFT1:  this->currentSprite = PACLEFT2;
                                    mouth = 1;
                        break;
                    case PACLEFT2:  if(mouth == 1)
                                        this->currentSprite = PACLEFT3;
                                    else
                                        this->currentSprite = PACLEFT1;
                        break;
                    case PACLEFT3:  if(mouth == 1)
                                        this->currentSprite = PACLEFT4;
                                    else
                                        this->currentSprite = PACLEFT2;
                        break;
                    case PACLEFT4:  if(mouth == 1)
                                        this->currentSprite = PACLEFT5;
                                    else
                                        this->currentSprite = PACLEFT3;
                        break;
                    case PACLEFT5:  this->currentSprite = PACLEFT4;
                                    mouth = -1;
                        break;
                    default: this->currentSprite = PACLEFT1;
                        break;
                }
            break;
    }
}
