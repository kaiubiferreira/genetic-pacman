#include <GL/glut.h>
#include <stdlib.h>
#include "geneticLib.h"
#include <windows.h>
#define IFB     0
#define IFLTE   1
#define APILL   2
#define RPILL   3
#define DISPILL 4
#define AGA     5
#define RGA     6
#define DISGA   7
#define AGB     8
#define RGBM    9
#define DISGB   10
#define AFOOD   11
#define DISU    12
#define AFRUIT  13
#define DISF    14
#define RETREAT 15



Pac pac;
Monster monster[4];
Scenario scenario;
int points = 0;
int foodCollected = 0;
int fruitCollected = 0;
int timer = 0;
int intFruitTimer = 0;
int blueStrike = 200;

void reset()
{
    points = 0;
    foodCollected = 0;
    fruitCollected = 0;
    timer = 0;
    intFruitTimer = 0;
    blueStrike = 200;

    //delete &pac;
    //delete[] monster;

    scenario.setFruitOnScreen(false);
    scenario.buildMatrix();

    pac = * new Pac(13, 7, scenario);
    monster[0] = * new Monster(13,16, scenario, 1, 100);
    monster[1] = * new Monster(14,16, scenario, 2, 250);
    monster[2] = * new Monster(14,17, scenario, 3, 300);
    monster[3] = * new Monster(13,17, scenario, 4, 350);
}

int oppositeDirection(int direction)
{
    int opposite;
    int x = pac.getRelativeX(), y = pac.getRelativeY();

    opposite = (direction + 2)%4;

    switch(opposite)
    {
        case 0: y++;
            break;
        case 1: x++;
            break;
        case 2: y--;
            break;
        case 3: x--;
            break;
    }

    if(Scenario::allowed(scenario.getValue(x, y)))
    {
        return opposite;
    }
    else
    {
        x = pac.getRelativeX();
        y = pac.getRelativeY();
        if(opposite%2 == 0)
        {
            if(Scenario::allowed(scenario.getValue(x + 1, y)))
                return 1;
            else
                return 3;
        }
        else
        {
            if(Scenario::allowed(scenario.getValue(x, y + 1)))
                return 0;
            else
                return 2;
        }
    }
}

int advanceToPill()
{
    pac.setNextDirection(scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), SPECIALFOOD));
    return pac.getNextDirection();
}

int retreatFromPill()
{
    int auxDirection = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), SPECIALFOOD);
    auxDirection = oppositeDirection(auxDirection);
    pac.setNextDirection(auxDirection);

    return pac.getNextDirection();
}

int distanceToPill()
{
    int auxDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), SPECIALFOOD, -1, -1, true);
    if(auxDistance == -1)
        return 9999;
    else
        return auxDistance;
}

int advanceToMonsterA()
{
    int minDistance;
    int auxDistance;
    int minMonster = 0;

    minDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[0].getRelativeX(), monster[0].getRelativeY(), true);

    for(int i = 1; i < 4; i++)
    {
        auxDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), true);
        if((auxDistance < minDistance || minDistance == -1) && (auxDistance != -1))
        {
            minDistance = auxDistance;
            minMonster = i;
        }
    }

    pac.setNextDirection(scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[minMonster].getRelativeX(), monster[minMonster].getRelativeY()));
    return pac.getNextDirection();
}

int retreatFromMonsterA()
{
    int minDistance = -1;
    int auxDistance;
    int minMonster = 0;
    int auxDirection = 1;

    minDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[0].getRelativeX(), monster[0].getRelativeY(), true);

    for(int i = 1; i < 4; i++)
    {
        auxDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), true);
        if((auxDistance < minDistance && auxDistance != -1) || (minDistance == -1))
        {
            minDistance = auxDistance;
            minMonster = i;
        }
    }

    auxDirection = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[minMonster].getRelativeX(), monster[minMonster].getRelativeY(), false);
    if(minDistance != -1)
    {
        auxDirection = oppositeDirection(auxDirection);
        pac.setNextDirection(auxDirection);
    }

    return pac.getNextDirection();
}

int distanceToMonsterA()
{
    int minDistance;
    int auxDistance;
    int minMonster = 0;

    minDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[0].getRelativeX(), monster[0].getRelativeY(), true);

    for(int i = 1; i < 4; i++)
    {
        auxDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), true);
        if(auxDistance < minDistance && auxDistance != -1)
        {
            minDistance = auxDistance;
            minMonster = i;
        }
    }

    return minDistance;
}

int advanceToMonsterB()
{
    int minDistance;
    int secondMinDistance = 999;
    int auxDistance;
    int minMonster = 0;
    int secondMinMonster = 0;

    minDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[0].getRelativeX(), monster[0].getRelativeY(), true);

    for(int i = 1; i < 4; i++)
    {
        auxDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), true);
        if((auxDistance <= minDistance || minDistance == -1) && (auxDistance != -1))
        {
            secondMinDistance = minDistance;
            minDistance = auxDistance;
            secondMinMonster = minMonster;
            minMonster = i;
        }
        else if(auxDistance < secondMinDistance && auxDistance != -1)
        {
            secondMinDistance = auxDistance;
            secondMinMonster = i;
        }
    }

    if(minDistance != -1)
    {
        pac.setNextDirection(scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[secondMinMonster].getRelativeX(), monster[secondMinMonster].getRelativeY()));
    }
    return pac.getNextDirection();
}

int retreatFromMonsterB()
{
    int minDistance;
    int secondMinDistance = 999;
    int auxDistance;
    int minMonster = 0;
    int secondMinMonster = 0;
    int auxDirection = pac.getDirection();

    minDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[0].getRelativeX(), monster[0].getRelativeY(), true);

    for(int i = 1; i < 4; i++)
    {
        auxDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), true);
        if((auxDistance <= minDistance || minDistance == -1) && (auxDistance != -1))
        {
            secondMinDistance = minDistance;
            minDistance = auxDistance;
            secondMinMonster = minMonster;
            minMonster = i;
        }
        else if(auxDistance < secondMinDistance && auxDistance != -1)
        {
            secondMinDistance = auxDistance;
            secondMinMonster = i;
        }
    }

    if(minDistance != -1)
    {
        auxDirection = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[secondMinMonster].getRelativeX(), monster[secondMinMonster].getRelativeY());
        auxDirection = oppositeDirection(auxDirection);
        pac.setNextDirection(auxDirection);
    }

    return pac.getNextDirection();
}

int distanceToMonsterB()
{
    int minDistance;
    int secondMinDistance = 999;
    int auxDistance;
    int secondMinMonster;
    int minMonster = 0;

    minDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[0].getRelativeX(), monster[0].getRelativeY(), true);

    for(int i = 1; i < 4; i++)
    {
        auxDistance = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), true);
        if((auxDistance <= minDistance || minDistance == -1) && (auxDistance != -1))
        {
            secondMinDistance = minDistance;
            minDistance = auxDistance;
            secondMinMonster = minMonster;
            minMonster = i;
        }
        else if(auxDistance < secondMinDistance && auxDistance != -1)
        {
            secondMinDistance = auxDistance;
            secondMinMonster = i;
        }
    }

    if(secondMinDistance == -1)
        secondMinDistance = 9999;

    return secondMinDistance;
}

int advanceToFruit()
{
    if(scenario.getFruitOnScreen())
    {
        pac.setNextDirection(scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), FRUIT1, -1, -1));
    }

    return pac.getNextDirection();
}

int distanceToFruit()
{
    if(scenario.getFruitOnScreen())
    {
        return scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), FRUIT1, -1, -1, true);
    }
    else
    {
        return 9999;
    }
}

int advanceToUneatedDot()
{
    pac.setNextDirection(scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), FOOD));
    return pac.getNextDirection();
}

int distanceToUneatedDot()
{
    return scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), FOOD, -1, -1, true);
}

int retreatFromMonster()
{
    int countDirections[]= {0, 0, 0, 0};
    int directions[] = {-1, -1, -1, -1};
    int distances[] = {-1, -1, -1, -1};
    int distancePerDirection[] = {-1, -1, -1, -1};
    int i;
    int x = pac.getRelativeX();
    int y = pac.getRelativeY();
    bool found = false; // Found a direction with 0 counts
    int maximum;

    for(i = rand()%4; i < 4; i++)
    {
        countDirections[i] = 0;
        directions[i] = -1;
        distances[i] = -1;
        if((monster[i].getState() == CHASE || monster[i].getState() == SCATTER) && monster[i].getBlue() == false)
        {
            directions[i] = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), false);
            distances[i] = scenario.shortestDistanceMaze(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), -1, monster[i].getRelativeX(), monster[i].getRelativeY(), true);

            if(distancePerDirection[directions[i]] == -1 || distancePerDirection[directions[i]] > distances[i])
            {
                distancePerDirection[directions[i]] = distances[i];
            }
        }
    }


    for(i = 0; i < 4; i++)
    {
        if(directions[i] != -1)
            countDirections[directions[i]]++;
    }

    for(i = 0; i < 4 && found == false; i++)
    {
        if(countDirections[i] == 0)
        {
            found = true;

            if(i == 0 && Scenario::allowed(scenario.getValue(x, y + 1)))
                pac.setNextDirection(i);
            else if(i == 1 && Scenario::allowed(scenario.getValue(x + 1, y)))
                pac.setNextDirection(i);
            else if(i == 2 && Scenario::allowed(scenario.getValue(x, y - 1)))
                pac.setNextDirection(i);
            else if(i == 3 && Scenario::allowed(scenario.getValue(x - 1, y)))
                pac.setNextDirection(i);
            else
                found = false;
        }
    }


    if(!found)
    {
        maximum = 0;
        for(i = 0; i < 4; i++)
        {
            if(distancePerDirection[i] > distancePerDirection[maximum])
            {
                maximum = i;
            }
        }
        pac.setNextDirection(maximum);
    }
    return pac.getNextDirection();
}

void controlSprites(int value)
{
    pac.updateCurrentSprite();
    monster[0].updateCurrentSprite();
    monster[1].updateCurrentSprite();
    monster[2].updateCurrentSprite();
    monster[3].updateCurrentSprite();

    glutPostRedisplay();
    glutTimerFunc(100, controlSprites, 0);
}

void changeBlueState(int m)
{
    monster[m].setBlue(false);
    monster[m].setSpeedRate(3);
    blueStrike = 200;
}

void fruitTimer()
{
    if(intFruitTimer == 175)
    {
        intFruitTimer = 0;
        scenario.setFruitOnScreen(false);
    }
    else
    {
        intFruitTimer++;
    }
}

void controlMonster(int m)
{
    int x = monster[m].getRelativeX();
    int y = monster[m].getRelativeY();

    switch(monster[m].getState())
    {
        case ATHOME:
                //monster[m].setNextDirection(rand()%4);
            break;
        case SCATTER:
                if(scenario.getValue(x, y) >= 100 && monster[m].lastChange >3)
                {
                    monster[m].setNextDirection(rand()%4, false);
                }
            break;
        case EXITHOME:
                monster[m].setNextDirection(0);
                if(monster[m].lastChange <= 1)
                    monster[m].setRelativeXY(13, 17);
            break;
        case ENTERHOME:
                monster[m].setNextDirection(2);
                if(monster[m].getRelativeX() >= 12 && monster[m].getRelativeX() <= 15 && monster[m].getRelativeY() <= 17 && monster[m].getRelativeY() >= 16)
                {
                    monster[m].setBlue(false);
                    monster[m].setEaten(false);
                    monster[m].setState(EXITHOME, -1);
                }
            break;

        case CHASE:
                if(monster[m].lastChange > monster[m].getSpeedRate() && scenario.getValue(x, y) >= 100)
                {
                    monster[m].setTarget(pac.getRelativeX(), pac.getRelativeY(), pac.getDirection(), monster[0].getRelativeX(), monster[0].getRelativeY());
                    monster[m].setNextDirection(scenario.shortestDistanceMaze(x, y, monster[m].getDirection(), -2, monster[m].getTargetX(), monster[m].getTargetY(), false), false);
                    if(m == 3)
                    {
                        if(20 > scenario.shortestDistanceCorners(pac.getRelativeX(), pac.getRelativeY(), monster[m].getRelativeX(), monster[m].getRelativeY()))
                        {
                            monster[m].setNextDirection(rand()%4, false);
                        }
                    }
                }
            break;
        case GOHOME:
                monster[m].setNextDirection(scenario.shortestDistanceMaze(x, y, monster[m].getDirection(), -1, 13, 19));
                if(monster[m].getRelativeX() == 13 && monster[m].getRelativeY() == 19)
                {
                    monster[m].correctPosition();
                    monster[m].setState(ENTERHOME, -1);
                }

                break;
    }

    switch(monster[m].getNextDirection())
    {
        case 0: y++;
            break;
        case 1: x++;
            break;
        case 2: y--;
            break;
        case 3: x--;
            break;
    }

    if(monster[m].getDirection() != monster[m].getNextDirection() && (Scenario::allowed(scenario.getValue(x, y)) || (scenario.getValue(x, y) == DOOR)))
    {
        monster[m].setDirection(monster[m].getNextDirection());
        monster[m].correctPosition();
        monster[m].lastChange = 0;
    }
    else if(Scenario::allowed(scenario.getValue(x, y)) || (scenario.getValue(x,y) == DOOR && (monster[m].getState() == EXITHOME || monster[m].getState() == ENTERHOME)))
    {
        monster[m].moveCharacter(scenario.getCellSize()/(monster[m].getSpeedRate()+0.23));
    }
    else if(monster[m].getState() == EXITHOME)
    {
        monster[m].setSpeedRate(3);
        monster[m].setNextDirection(1);
        monster[m].setState(CHASE, 1000); // EXITHOME to Chase
    }

    if((x == 28) && (y == 13 || y == 22))
    {
        monster[m].setRelativeXY(0, y);
    }
    else if((x == -1) && (y == 13 || y == 22))
    {
        monster[m].setRelativeXY(27, y);
    }

    monster[m].increaseStateTimer();
    monster[m].lastChange++;

    //monster[m].moveCharacter(scenario.getCellSize()/monster[m].getSpeedRate());
}

void controlPacMan()
{
    int x = pac.getRelativeX();
    int y = pac.getRelativeY();

    switch(pac.getNextDirection())
    {
        case 0: y += 1;
            break;
        case 1: x += 1;
            break;
        case 2: y -= 1;
            break;
        case 3: x -= 1;
            break;
    }

    if(pac.getDirection() != pac.getNextDirection() && Scenario::allowed(scenario.getValue(x, y)))
    {
        pac.setDirection(pac.getNextDirection());
        pac.correctPosition();
    }
    else
    {
        x = pac.getRelativeX();
        y = pac.getRelativeY();

        switch(pac.getDirection())
        {
            case 0: y++;
                break;
            case 1: x++;
                break;
            case 2: y--;
                break;
            case 3: x--;
                break;
        }

        if(Scenario::allowed(scenario.getValue(x, y)))
            pac.moveCharacter(scenario.getCellSize()/3);
        else if((x == 28) && (y == 13 || y == 22))
        {
            pac.setRelativeXY(0, y);
        }
        else if((x == -1) && (y == 13 || y == 22))
        {
            pac.setRelativeXY(27, y);
        }
        else
        {
            pac.correctPosition();
        }
    }
}

int checkPacCollision()
{
    int cell;

    cell = scenario.getValue(pac.getRelativeX(), pac.getRelativeY());

    switch(cell)
    {
        case FOOD:
                    points += 10;
                    foodCollected++;
                    scenario.setValue(pac.getRelativeX(), pac.getRelativeY(), EMPTY);
            break;
        case SPECIALFOOD:
                    points += 50;
                    for(int i = 0; i < 4; i++)
                    {
                        //if(monster[i].getState() != ATHOME) // NORMAL TO BLUE
                        {
                            monster[i].setBlue(true);
                            monster[i].setSpeedRate(5);
                        }
                    }
                    scenario.setValue(pac.getRelativeX(), pac.getRelativeY(), EMPTY);
                    blueStrike = 200;
            break;
        case FRUIT1:
                    points += 2000;
                    if(foodCollected < 150)
                        fruitCollected = 1;
                    else
                        fruitCollected = 2;

                    scenario.setFruitOnScreen(false);
            break;
    }


    if(cell >= 100 && cell < 200)
    {
        cell += 100;
        scenario.setValue(pac.getRelativeX(), pac.getRelativeY(), cell);
        foodCollected++;
    }

    if(foodCollected == 60 && scenario.getFruitOnScreen() == false && fruitCollected == 0)
    {
        scenario.setFruitOnScreen(true);
        intFruitTimer = 0;
    }
    else if(foodCollected == 150 && scenario.getFruitOnScreen() == false && fruitCollected == 1)
    {
        scenario.setFruitOnScreen(true);
        intFruitTimer = 0;
    }

    // Collected all food
    if(foodCollected == 222)
    {
        return points;
    }

    // Pac Collide with monster
    for(int i = 0; i < 4; i++)
    {
        if(pac.getRelativeX() == monster[i].getRelativeX() && pac.getRelativeY() == monster[i].getRelativeY())
        {
            if(monster[i].getBlue() && monster[i].getState() != GOHOME)
            {
                monster[i].setState(GOHOME, -1);
                monster[i].setEaten(true);
                monster[i].setSpeedRate(3);
                points += blueStrike;
                blueStrike *= 2;
            }
            else if(monster[i].getState() != GOHOME && monster[i].getState() != ENTERHOME && monster[i].getEaten() == false)
            {
                // Game over
                return points;
            }
        }
    }
    return -1;
}

int calculateSExpression(struct tNode * node)
{
    switch(node->value)
    {
        case IFB:   if(monster[0].getBlue() && monster[1].getBlue() && monster[2].getBlue() && monster[3].getBlue())
                        return calculateSExpression(node->son[0]);
                    else
                        return calculateSExpression(node->son[1]);
            break;
        case IFLTE: if(calculateSExpression(node->son[0]) <= calculateSExpression(node->son[1]))
                        return calculateSExpression(node->son[2]);
                    else
                        return calculateSExpression(node->son[3]);

            break;
        case APILL:     return advanceToPill();
            break;
        case RPILL:     return retreatFromPill();
            break;
        case DISPILL:   return distanceToPill();
            break;
        case AGA:       return advanceToMonsterA();
            break;
        case RGA:       return retreatFromMonsterA();
            break;
        case DISGA:     return distanceToMonsterA();
            break;
        case AGB:       return advanceToMonsterB();
            break;
        case RGBM:      return retreatFromMonsterB();
            break;
        case DISGB:     return distanceToMonsterB();
            break;
        case AFOOD:     return advanceToUneatedDot();
            break;
        case DISU:      return distanceToUneatedDot();
            break;
        case AFRUIT:    return advanceToFruit();
            break;
        case DISF:      return distanceToFruit();
            break;
        case RETREAT:   return retreatFromMonster();
            break;
    }
}

void controlMovements(struct tNode * node)
{
    if(node != NULL)
        calculateSExpression(node);

    controlPacMan();

    for(int i = 0; i < 4; i++)
    {
        controlMonster(i);

        if(monster[i].getBlue())
            monster[i].increaseBlueTimer();
    }

    fruitTimer();
    timer++;
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -2.0f);
    glScalef(0.32, 0.32f, 0.32f);

    glPushMatrix();
        scenario.drawMatrix();
        pac.drawCharacter();

        for(int i = 0; i < 4; i++)
        {
            monster[i].drawCharacter();
        }

    glPopMatrix();

    glutSwapBuffers();
}

void key(unsigned char key, int var1, int var2)
{
    switch (key)
    {
        case 27 :
            exit(0);
            break;
        case 'w':   pac.setNextDirection(0);
            break;
        case 'd':   pac.setNextDirection(1);
            break;
        case 's':   pac.setNextDirection(2);
            break;
        case 'a':   pac.setNextDirection(3);
            break;
        case 'c':   pac.correctPosition();
            break;
    }
}

void printGene(struct tNode * node)
{
    switch(node->value)
    {
        case IFB:       cout << "IFB(2) ";
            break;
        case IFLTE:     cout << "IFLTE(4) ";
            break;
        case APILL:     cout << "APILL ";
            break;
        case RPILL:     cout << "RPILL ";
            break;
        case DISPILL:   cout << "DISPILL ";
            break;
        case AGA:       cout << "AGA ";
            break;
        case RGA:       cout << "RGA ";
            break;
        case RGBM:      cout << "RGB ";
            break;
        case DISGA:     cout << "DISGA ";
            break;
        case AGB:       cout << "AGB ";
            break;
        case DISGB:     cout << " DISGB ";
            break;
        case AFOOD:     cout << "AFOOD ";
            break;
        case DISU:      cout << "DISU ";
            break;
        case AFRUIT:    cout << "AFRUIT ";
            break;
        case DISF:      cout << "DISF ";
            break;
        case RETREAT:   cout << "RETREAT ";
            break;
    }
}

float rawFitness(struct tNode * node, bool simulate)
{
    simulate = true;

    float returnPoints;
    reset();
    do
    {
        controlMovements(node);

        controlSprites(0);
        returnPoints = checkPacCollision();

        if(simulate)
            display();

        if(timer >= 8000)
            returnPoints;

    }while(returnPoints == -1);

    return returnPoints;
}

void geneticControl()
{
    scenario = * new Scenario(0.20f);
    pac = * new Pac(13,7, scenario);

    struct tProperty p;
    p.populationSize = 100;
    p.generations = 51;
    p.mutationProbality = 0.01;
    p.reproductionProbability = 0.1;
    p.crossOverProbability = 0.9;
    p.terminalQuantity = 14;
    p.functionQuantity = 2;
    p.maxFitness = 30000;
    p.randomConstant.blnHas = 0;
    p.blnOverSelection = false;
    p.overSelectionProportion = 0.36;
    p.blnHasInputFile = false;

    int function[2] = {2,4};
    startLife(p, function);
    exit(0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    Settings settings = *new Settings(geneticControl, "Pacman", 800, 680);

    glutKeyboardFunc(key);
    glutMainLoop();
    return EXIT_SUCCESS;
}
