#include "Scenario.h"
//Monster states
#define ATHOME      0
#define EXITHOME    1
#define CHASE       2
#define SCATTER     3
#define GOHOME      4
#define ENTERHOME   5

class Characters
{
    private:

    protected:
        int relativeX, relativeY;
        float actualX, actualY;
        float scenarioStartPositionX;
        float scenarioStartPositionY;
        float cellSize;
        int direction;
        int nextDirection;
        int currentSprite;
        Texture textureSet;

    public:
        int lastChange;
        void setDirection(int);
        int getDirection();
        void setNextDirection(int, bool allowReverse = true);
        int getNextDirection();
        void calculateRelativePositions();
        void correctPosition();
        void setRelativeXY(int, int);
        int getRelativeX();
        int getRelativeY();
        void moveCharacter(float pace);
        void drawCharacter();
};

class Monster : public Characters
{
    private:
            int id;
            int state;
            int stateTimer; // Chase, random 500 steps chasing, 175 scatter
            int stateTimerMax;
            int blueTimer;
            bool blue;
            bool eaten;
            int targetX, targetY;
            int speedRate;

    public:
            Monster(){};

            Monster(int startPositionX, int startPositionY, Scenario scenario, int id, int stateTimerMax);
            void updateCurrentSprite();
            int getState();
            void setState(int state, int timer);
            void increaseStateTimer();
            void increaseBlueTimer();
            void setBlue(bool pacEnergized);
            bool getBlue();
            void setEaten(bool);
            bool getEaten();
            void setTarget(int pacX, int pacY, int pacDirection, int blinkyX, int blinkyY);
            int getTargetX();
            int getTargetY();
            int getSpeedRate();
            void setSpeedRate(int);
            void drawTarget();
};

class Pac : public Characters
{
    private:
            int mouth = 1; // 1 = Opening, -1 Closing

    public:
            Pac(){}
            Pac(int startPositionX, int startPositionY, Scenario scenario);
            void updateCurrentSprite();
};
