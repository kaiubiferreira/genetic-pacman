#include "Characters.h"


Monster::Monster(int pacStartPositionX, int pacStartPositionY, Scenario scenario, int id, int stateTimerMax)
{
    this->id = id;
    this->direction = 1;
    this->cellSize = scenario.getCellSize();
    this->textureSet = scenario.getTextureSet();
    this->scenarioStartPositionX = scenario.getStartPositionX();
    this->scenarioStartPositionY = scenario.getStartPositionY() - scenario.getCellSize();
    this->relativeX = pacStartPositionX;
    this->relativeY = pacStartPositionY;

    this->targetX = 0;
    this->targetY = 0;
    this->state = 0;
    this->stateTimer = 0;
    this->stateTimerMax = stateTimerMax;
    this->lastChange = 0;
    this->blue = false;
    this->eaten = false;
    this->speedRate = 10;
    this->blueTimer = 0;

    switch(id)
    {
        case 1: this->currentSprite = MONSTER1R1;
            break;
        case 2: this->currentSprite = MONSTER2R1;
            break;
        case 3: this->currentSprite = MONSTER3R1;
            break;
        case 4: this->currentSprite = MONSTER4R1;
            break;
        case 5: this->currentSprite = MONSTER51;
            break;
    }


    correctPosition();
}

void Monster::updateCurrentSprite()
{
    switch(direction)
    {
        case 0:
                if(this->eaten)
                    this->currentSprite = EYEU;
                else
                    switch(this->currentSprite)
                    {
                        case MONSTER1U1:    this->currentSprite = MONSTER1U2;
                            break;
                        case MONSTER1U2:    this->currentSprite = MONSTER1U1;
                            break;
                        case MONSTER2U1:    this->currentSprite = MONSTER2U2;
                            break;
                        case MONSTER2U2:    this->currentSprite = MONSTER2U1;
                            break;
                        case MONSTER3U1:    this->currentSprite = MONSTER3U2;
                            break;
                        case MONSTER3U2:    this->currentSprite = MONSTER3U1;
                            break;
                        case MONSTER4U1:    this->currentSprite = MONSTER4U2;
                            break;
                        case MONSTER4U2:    this->currentSprite = MONSTER4U1;
                            break;
                        case MONSTER51:    this->currentSprite = MONSTER52;
                            break;
                        case MONSTER52:    this->currentSprite = MONSTER53;
                            break;
                        case MONSTER53:    this->currentSprite = MONSTER54;
                            break;
                        case MONSTER54:    this->currentSprite = MONSTER51;
                            break;
                        default:    switch(id)
                                    {
                                        case 1: this->currentSprite = MONSTER1U1;
                                            break;
                                        case 2: this->currentSprite = MONSTER2U1;
                                            break;
                                        case 3: this->currentSprite = MONSTER3U1;
                                            break;
                                        case 4: this->currentSprite = MONSTER4U1;
                                            break;
                                    }
                            break;
                    }
            break;
        case 1:
                if(this->eaten)
                    this->currentSprite = EYER;
                else
                    switch(this->currentSprite)
                    {
                        case MONSTER1R1:    this->currentSprite = MONSTER1R2;
                            break;
                        case MONSTER1R2:    this->currentSprite = MONSTER1R1;
                            break;
                        case MONSTER2R1:    this->currentSprite = MONSTER2R2;
                            break;
                        case MONSTER2R2:    this->currentSprite = MONSTER2R1;
                            break;
                        case MONSTER3R1:    this->currentSprite = MONSTER3R2;
                            break;
                        case MONSTER3R2:    this->currentSprite = MONSTER3R1;
                            break;
                        case MONSTER4R1:    this->currentSprite = MONSTER4R2;
                            break;
                        case MONSTER4R2:    this->currentSprite = MONSTER4R1;
                            break;
                        case MONSTER51:    this->currentSprite = MONSTER52;
                            break;
                        case MONSTER52:    this->currentSprite = MONSTER53;
                            break;
                        case MONSTER53:    this->currentSprite = MONSTER54;
                            break;
                        case MONSTER54:    this->currentSprite = MONSTER51;
                            break;
                        default:    switch(id)
                                    {
                                        case 1: this->currentSprite = MONSTER1R1;
                                            break;
                                        case 2: this->currentSprite = MONSTER2R1;
                                            break;
                                        case 3: this->currentSprite = MONSTER3R1;
                                            break;
                                        case 4: this->currentSprite = MONSTER4R1;
                                            break;
                                    }
                            break;
                    }
            break;
        case 2:
                if(this->eaten)
                    this->currentSprite = EYED;
                else
                    switch(this->currentSprite)
                    {
                        case MONSTER1D1:    this->currentSprite = MONSTER1D2;
                            break;
                        case MONSTER1D2:    this->currentSprite = MONSTER1D1;
                            break;
                        case MONSTER2D1:    this->currentSprite = MONSTER2D2;
                            break;
                        case MONSTER2D2:    this->currentSprite = MONSTER2D1;
                            break;
                        case MONSTER3D1:    this->currentSprite = MONSTER3D2;
                            break;
                        case MONSTER3D2:    this->currentSprite = MONSTER3D1;
                            break;
                        case MONSTER4D1:    this->currentSprite = MONSTER4D2;
                            break;
                        case MONSTER4D2:    this->currentSprite = MONSTER4D1;
                            break;
                        case MONSTER51:    this->currentSprite = MONSTER52;
                            break;
                        case MONSTER52:    this->currentSprite = MONSTER53;
                            break;
                        case MONSTER53:    this->currentSprite = MONSTER54;
                            break;
                        case MONSTER54:    this->currentSprite = MONSTER51;
                            break;
                        default:    switch(id)
                                    {
                                        case 1: this->currentSprite = MONSTER1D1;
                                            break;
                                        case 2: this->currentSprite = MONSTER2D1;
                                            break;
                                        case 3: this->currentSprite = MONSTER3D1;
                                            break;
                                        case 4: this->currentSprite = MONSTER4D1;
                                            break;
                                    }
                            break;
                    }
            break;
        case 3:
                if(this->eaten)
                    this->currentSprite = EYEL;
                else
                    switch(this->currentSprite)
                    {
                        case MONSTER1L1:    this->currentSprite = MONSTER1L2;
                            break;
                        case MONSTER1L2:    this->currentSprite = MONSTER1L1;
                            break;
                        case MONSTER2L1:    this->currentSprite = MONSTER2L2;
                            break;
                        case MONSTER2L2:    this->currentSprite = MONSTER2L1;
                            break;
                        case MONSTER3L1:    this->currentSprite = MONSTER3L2;
                            break;
                        case MONSTER3L2:    this->currentSprite = MONSTER3L1;
                            break;
                        case MONSTER4L1:    this->currentSprite = MONSTER4L2;
                            break;
                        case MONSTER4L2:    this->currentSprite = MONSTER4L1;
                            break;
                        case MONSTER51:    this->currentSprite = MONSTER52;
                            break;
                        case MONSTER52:    this->currentSprite = MONSTER53;
                            break;
                        case MONSTER53:    this->currentSprite = MONSTER54;
                            break;
                        case MONSTER54:    this->currentSprite = MONSTER51;
                            break;
                        default:    switch(id)
                                    {
                                        case 1: this->currentSprite = MONSTER1L1;
                                            break;
                                        case 2: this->currentSprite = MONSTER2L1;
                                            break;
                                        case 3: this->currentSprite = MONSTER3L1;
                                            break;
                                        case 4: this->currentSprite = MONSTER4L1;
                                            break;
                                    }
                            break;
                    }
            break;
    }
}

int Monster::getState()
{
    return this->state;
}

void Monster::increaseStateTimer()
{
    if(this->stateTimer < this->stateTimerMax)
    {
        if(id == 0)
        cout << stateTimer << " " << stateTimerMax << endl;
        this->stateTimer++;
    }
    else if(this->stateTimerMax > -1)
    {
        switch(this->state)
        {
            case ATHOME:    setState(EXITHOME, -1);
                            this->lastChange = 0;
                break;
            case CHASE: setState(SCATTER, 400);
                break;
            case SCATTER: setState(CHASE, 900);
                break;
        }
    }
}

void Monster::setBlue(bool blue)
{
    this->blue = blue;
    this->blueTimer = 0;

    if(blue)
    {
        this->setSpeedRate(5);
        this->currentSprite = MONSTER51;
    }
    else
    {
        this->setSpeedRate(3);
        switch(id)
        {
            case 1: this->currentSprite = MONSTER1R1;
                break;
            case 2: this->currentSprite = MONSTER2R1;
                break;
            case 3: this->currentSprite = MONSTER3R1;
                break;
            case 4: this->currentSprite = MONSTER4R1;
                break;
            case 5: this->currentSprite = MONSTER51;
                break;
        }
    }
}

bool Monster::getBlue()
{
    return this->blue;
}

void Monster::setTarget(int pacX, int pacY, int pacDirection, int blinkyX, int blinkyY)
{
    switch(this->id - 1)
    {
        case 0: // Blinky
        case 3: // Clyde
            this->targetX = pacX;
            this->targetY = pacY;
            break;
        case 1: // Inky
            switch(pacDirection)
            {
                case 0:
                        targetX = pacX;
                        targetY = pacY + 4;
                    break;
                case 1:
                        targetX = pacX + 4;
                        targetY = pacY;
                    break;
                case 2:
                        targetX = pacX;
                        targetY = pacY - 4;
                    break;
                case 3: targetX = pacX - 4;
                        targetY = pacY;
                    break;
            }
            targetX = 2 * targetX - blinkyX;
            targetY = 2 * targetY - blinkyY;
            if(targetX < 1)
                targetX = 1;
            if(targetX > 26)
                targetX = 26;
            if(targetY < 1)
                targetY = 1;
            if(targetY > 30)
                targetY = 30;
            break;
        case 2: // Pinky
            switch(pacDirection)
            {
                case 0:
                        targetX = pacX;
                        targetY = pacY + 4;
                    break;
                case 1:
                        targetX = pacX + 4;
                        targetY = pacY;
                    break;
                case 2:
                        targetX = pacX;
                        targetY = pacY - 4;
                    break;
                case 3: targetX = pacX - 4;
                        targetY = pacY;
                    break;
            }
            if(targetX < 1)
                targetX = 1;
            if(targetX > 26)
                targetX = 26;
            if(targetY < 1)
                targetY = 1;
            if(targetY > 29)
                targetY = 29;
            break;
    }
}

int Monster::getSpeedRate()
{
    return this->speedRate;
}

void Monster::setSpeedRate(int rate)
{
    this->speedRate = rate;
}

int Monster::getTargetX()
{
    return this->targetX;
}

int Monster::getTargetY()
{
    return this->targetY;
}

void Monster::setState(int state, int timer)
{
    this->state = state;
    this->stateTimerMax = timer;
    this->stateTimer = 0;
}

void Monster::setEaten(bool eaten)
{
    this->eaten = eaten;
}

bool Monster::getEaten()
{
    return this->eaten;
}

void Monster::increaseBlueTimer()
{
    this->blueTimer++;
    if(blueTimer == 70)
    {
        blueTimer = 0;
        if(this->blue)
            setBlue(false);
    }
}
