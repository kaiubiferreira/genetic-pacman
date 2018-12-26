#include "Sprites.h"
#include "Square.h"
#include "Queue.h"

struct tTarget
{
    int directionFromSource;
    int object;
    int targetX;
    int targetY;
    int distance;
};

class Scenario
{
    private:
            int mainMatrix[31][28];
            int distanceMatrix[68][68];
            int listVisitedEdges[68];
            int lookUpMatrix[28][31];
            bool fruitOnScreen;

            Texture textureSet;
            GLfloat cellSize;
            GLfloat startPositionX;
            GLfloat startPositionY;
    public:
            Scenario();
            Scenario(float cellSize);
            void buildMatrix();
            void clearListVisitedEdges();
            void clearLookupMatrix();
            void drawMatrix();
            void buildDistanceMatrix();
            GLfloat getCellSize();
            GLfloat getStartPositionX();
            GLfloat getStartPositionY();
            Texture getTextureSet();
            void setValue(int, int, int);
            int getValue(int, int);
            int getDistanceEdge(int, int);
            void setFruitOnScreen(bool);
            bool getFruitOnScreen();

            static bool allowed(int x)
            {
                if(x >= 100)
                    return true;

                if(x == -1)
                {
                    return false;
                }


                switch (x)
                {
                    case FOOD:
                    case EMPTY:
                    case SPECIALFOOD:
                    case FRUIT1:
                        return true;
                    default:
                        return false;
                }
            }

            void correctTarget(struct tTarget * target);
            int shortestDistanceCorners(int targetX, int targetY, int originX, int originY);
            int addNode(int node, int nodeX, int nodeY);
            void graphShortestDistance(int sourceNode, struct tTarget * target, int startDistance);
            void lookTarget(int x, int y, int direction, int distance, struct tTarget * target, int directionFromSource);
            int shortestDistanceMaze(int sourceX, int sourceY, int direction, int targetObject, int targetX = -1, int targetY = -1, bool blnGetDist = false);
};
