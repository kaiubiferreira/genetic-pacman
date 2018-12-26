#include "Characters.h"


class Monster : public Characters
{
    private:
            int mouth = 1; // 1 = Opening, -1 Closing

    public:
            Monster(){}
            Monster(int startPositionX, int startPositionY, Scenario scenario);
            void updateCurrentSprite();
};
