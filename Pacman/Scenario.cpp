#include "Scenario.h"


Scenario::Scenario(){}

Scenario::Scenario(float cellSize)
{
    Sprites sprites = *new Sprites();
    textureSet = *new Texture(sprites.getImages(), sprites.getQuantity());

    this->cellSize = cellSize;
    this->startPositionX = -3.0f;
    this->startPositionY = -2.9f;
    this->fruitOnScreen = false;

    buildMatrix();
    buildDistanceMatrix();

    delete &sprites;
}

void Scenario::clearListVisitedEdges()
{
    for(int i = 0; i < 68; i++)
    {
        this->listVisitedEdges[i] = -1;
    }
}

void Scenario::clearLookupMatrix()
{
    int i = 0;
    int j = 0;
    for(i = 0; i < 28; i++)
    {
        for(j = 0; j < 31; j++)
        {
            this->lookUpMatrix[i][j] = -1;
        }
    }
}

void Scenario::buildMatrix()
{
    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < 28; j++)
        {
            this->mainMatrix[i][j] = 0;
        }
    }

    this->mainMatrix[30][0] = MNW;
    this->mainMatrix[30][1] = MD;
    this->mainMatrix[30][2] = MD;
    this->mainMatrix[30][3] = MD;
    this->mainMatrix[30][4] = MD;
    this->mainMatrix[30][5] = MD;
    this->mainMatrix[30][6] = MD;
    this->mainMatrix[30][7] = MNE;
    this->mainMatrix[30][8] = MNW;
    this->mainMatrix[30][9] = MD;
    this->mainMatrix[30][10] = MD;
    this->mainMatrix[30][11] = MD;
    this->mainMatrix[30][12] = MD;
    this->mainMatrix[30][13] = MD;
    this->mainMatrix[30][14] = MD;
    this->mainMatrix[30][15] = MD;
    this->mainMatrix[30][16] = MD;
    this->mainMatrix[30][17] = MD;
    this->mainMatrix[30][18] = MD;
    this->mainMatrix[30][19] = MNE;
    this->mainMatrix[30][20] = MNW;
    this->mainMatrix[30][21] = MD;
    this->mainMatrix[30][22] = MD;
    this->mainMatrix[30][23] = MD;
    this->mainMatrix[30][24] = MD;
    this->mainMatrix[30][25] = MD;
    this->mainMatrix[30][26] = MD;
    this->mainMatrix[30][27] = MNE;

    this->mainMatrix[29][0] = MU;
    this->mainMatrix[29][1] = 100;
    this->mainMatrix[29][2] = FOOD;
    this->mainMatrix[29][3] = FOOD;
    this->mainMatrix[29][4] = FOOD;
    this->mainMatrix[29][5] = FOOD;
    this->mainMatrix[29][6] = 101;
    this->mainMatrix[29][7] = MU;
    this->mainMatrix[29][8] = MU;
    this->mainMatrix[29][9] = 102;
    this->mainMatrix[29][10] = FOOD;
    this->mainMatrix[29][11] = FOOD;
    this->mainMatrix[29][12] = FOOD;
    this->mainMatrix[29][13] = FOOD;
    this->mainMatrix[29][14] = FOOD;
    this->mainMatrix[29][15] = FOOD;
    this->mainMatrix[29][16] = FOOD;
    this->mainMatrix[29][17] = FOOD;
    this->mainMatrix[29][18] = 103;
    this->mainMatrix[29][19] = MU;
    this->mainMatrix[29][20] = MU;
    this->mainMatrix[29][21] = 104;
    this->mainMatrix[29][22] = FOOD;
    this->mainMatrix[29][23] = FOOD;
    this->mainMatrix[29][24] = FOOD;
    this->mainMatrix[29][25] = FOOD;
    this->mainMatrix[29][26] = 105;
    this->mainMatrix[29][27] = MU;

    this->mainMatrix[28][0] = MU;
    this->mainMatrix[28][1] = SPECIALFOOD;
    this->mainMatrix[28][2] = MNW;
    this->mainMatrix[28][3] = MD;
    this->mainMatrix[28][4] = MD;
    this->mainMatrix[28][5] = MNE;
    this->mainMatrix[28][6] = FOOD;
    this->mainMatrix[28][7] = MU;
    this->mainMatrix[28][8] = MU;
    this->mainMatrix[28][9] = FOOD;
    this->mainMatrix[28][10] = MNW;
    this->mainMatrix[28][11] = MD;
    this->mainMatrix[28][12] = MD;
    this->mainMatrix[28][13] = MD;
    this->mainMatrix[28][14] = MD;
    this->mainMatrix[28][15] = MD;
    this->mainMatrix[28][16] = MD;
    this->mainMatrix[28][17] = MNE;
    this->mainMatrix[28][18] = FOOD;
    this->mainMatrix[28][19] = MU;
    this->mainMatrix[28][20] = MU;
    this->mainMatrix[28][21] = FOOD;
    this->mainMatrix[28][22] = MNW;
    this->mainMatrix[28][23] = MD;
    this->mainMatrix[28][24] = MD;
    this->mainMatrix[28][25] = MNE;
    this->mainMatrix[28][26] = SPECIALFOOD;
    this->mainMatrix[28][27] = MU;

    this->mainMatrix[27][0] = MU;
    this->mainMatrix[27][1] = FOOD;
    this->mainMatrix[27][2] = MSW;
    this->mainMatrix[27][3] = MD;
    this->mainMatrix[27][4] = MD;
    this->mainMatrix[27][5] = MSE;
    this->mainMatrix[27][6] = FOOD;
    this->mainMatrix[27][7] = MSW;
    this->mainMatrix[27][8] = MSE;
    this->mainMatrix[27][9] = FOOD;
    this->mainMatrix[27][10] = MSW;
    this->mainMatrix[27][11] = MD;
    this->mainMatrix[27][12] = MD;
    this->mainMatrix[27][13] = MD;
    this->mainMatrix[27][14] = MD;
    this->mainMatrix[27][15] = MD;
    this->mainMatrix[27][16] = MD;
    this->mainMatrix[27][17] = MSE;
    this->mainMatrix[27][18] = FOOD;
    this->mainMatrix[27][19] = MSW;
    this->mainMatrix[27][20] = MSE;
    this->mainMatrix[27][21] = FOOD;
    this->mainMatrix[27][22] = MSW;
    this->mainMatrix[27][23] = MD;
    this->mainMatrix[27][24] = MD;
    this->mainMatrix[27][25] = MSE;
    this->mainMatrix[27][26] = FOOD;
    this->mainMatrix[27][27] = MU;

    this->mainMatrix[26][0] = MU;
    this->mainMatrix[26][1] = 106;
    this->mainMatrix[26][2] = FOOD;
    this->mainMatrix[26][3] = 107;
    this->mainMatrix[26][4] = FOOD;
    this->mainMatrix[26][5] = FOOD;
    this->mainMatrix[26][6] = 108;
    this->mainMatrix[26][7] = FOOD;
    this->mainMatrix[26][8] = FOOD;
    this->mainMatrix[26][9] = 109;
    this->mainMatrix[26][10] = FOOD;
    this->mainMatrix[26][11] = FOOD;
    this->mainMatrix[26][12] = 110;
    this->mainMatrix[26][13] = FOOD;
    this->mainMatrix[26][14] = FOOD;
    this->mainMatrix[26][15] = 111;
    this->mainMatrix[26][16] = FOOD;
    this->mainMatrix[26][17] = FOOD;
    this->mainMatrix[26][18] = 112;
    this->mainMatrix[26][19] = FOOD;
    this->mainMatrix[26][20] = FOOD;
    this->mainMatrix[26][21] = 113;
    this->mainMatrix[26][22] = FOOD;
    this->mainMatrix[26][23] = FOOD;
    this->mainMatrix[26][24] = 114;
    this->mainMatrix[26][25] = FOOD;
    this->mainMatrix[26][26] = 115;
    this->mainMatrix[26][27] = MU;

    this->mainMatrix[25][0] = MCW;
    this->mainMatrix[25][1] = MD;
    this->mainMatrix[25][2] = MNE;
    this->mainMatrix[25][3] = FOOD;
    this->mainMatrix[25][4] = MNW;
    this->mainMatrix[25][5] = MNE;
    this->mainMatrix[25][6] = FOOD;
    this->mainMatrix[25][7] = MNW;
    this->mainMatrix[25][8] = MD;
    this->mainMatrix[25][9] = MD;
    this->mainMatrix[25][10] = MD;
    this->mainMatrix[25][11] = MNE;
    this->mainMatrix[25][12] = FOOD;
    this->mainMatrix[25][13] = MNW;
    this->mainMatrix[25][14] = MNE;
    this->mainMatrix[25][15] = FOOD;
    this->mainMatrix[25][16] = MNW;
    this->mainMatrix[25][17] = MD;
    this->mainMatrix[25][18] = MD;
    this->mainMatrix[25][19] = MD;
    this->mainMatrix[25][20] = MNE;
    this->mainMatrix[25][21] = FOOD;
    this->mainMatrix[25][22] = MNW;
    this->mainMatrix[25][23] = MNE;
    this->mainMatrix[25][24] = FOOD;
    this->mainMatrix[25][25] = MNW;
    this->mainMatrix[25][26] = MD;
    this->mainMatrix[25][27] = MCE;

    this->mainMatrix[24][0] = MU;
    this->mainMatrix[24][1] = WALL;
    this->mainMatrix[24][2] = MU;
    this->mainMatrix[24][3] = FOOD;
    this->mainMatrix[24][4] = MU;
    this->mainMatrix[24][5] = MU;
    this->mainMatrix[24][6] = FOOD;
    this->mainMatrix[24][7] = MU;
    this->mainMatrix[24][8] = WALL;
    this->mainMatrix[24][9] = WALL;
    this->mainMatrix[24][10] = WALL;
    this->mainMatrix[24][11] = MU;
    this->mainMatrix[24][12] = FOOD;
    this->mainMatrix[24][13] = MU;
    this->mainMatrix[24][14] = MU;
    this->mainMatrix[24][15] = FOOD;
    this->mainMatrix[24][16] = MU;
    this->mainMatrix[24][17] = WALL;
    this->mainMatrix[24][18] = WALL;
    this->mainMatrix[24][19] = WALL;
    this->mainMatrix[24][20] = MU;
    this->mainMatrix[24][21] = FOOD;
    this->mainMatrix[24][22] = MU;
    this->mainMatrix[24][23] = MU;
    this->mainMatrix[24][24] = FOOD;
    this->mainMatrix[24][25] = MU;
    this->mainMatrix[24][26] = WALL;
    this->mainMatrix[24][27] = MU;

    this->mainMatrix[23][0] = MSW;
    this->mainMatrix[23][1] = MD;
    this->mainMatrix[23][2] = MSE;
    this->mainMatrix[23][3] = FOOD;
    this->mainMatrix[23][4] = MU;
    this->mainMatrix[23][5] = MU;
    this->mainMatrix[23][6] = FOOD;
    this->mainMatrix[23][7] = MSW;
    this->mainMatrix[23][8] = MD;
    this->mainMatrix[23][9] = MD;
    this->mainMatrix[23][10] = MD;
    this->mainMatrix[23][11] = MSE;
    this->mainMatrix[23][12] = FOOD;
    this->mainMatrix[23][13] = MU;
    this->mainMatrix[23][14] = MU;
    this->mainMatrix[23][15] = FOOD;
    this->mainMatrix[23][16] = MSW;
    this->mainMatrix[23][17] = MD;
    this->mainMatrix[23][18] = MD;
    this->mainMatrix[23][19] = MD;
    this->mainMatrix[23][20] = MSE;
    this->mainMatrix[23][21] = FOOD;
    this->mainMatrix[23][22] = MU;
    this->mainMatrix[23][23] = MU;
    this->mainMatrix[23][24] = FOOD;
    this->mainMatrix[23][25] = MSW;
    this->mainMatrix[23][26] = MD;
    this->mainMatrix[23][27] = MSE;

    this->mainMatrix[22][0] = EMPTY;
    this->mainMatrix[22][1] = EMPTY;
    this->mainMatrix[22][2] = EMPTY;
    this->mainMatrix[22][3] = 116;
    this->mainMatrix[22][4] = MU;
    this->mainMatrix[22][5] = MU;
    this->mainMatrix[22][6] = 117;
    this->mainMatrix[22][7] = FOOD;
    this->mainMatrix[22][8] = FOOD;
    this->mainMatrix[22][9] = 118;
    this->mainMatrix[22][10] = FOOD;
    this->mainMatrix[22][11] = FOOD;
    this->mainMatrix[22][12] = 119;
    this->mainMatrix[22][13] = MU;
    this->mainMatrix[22][14] = MU;
    this->mainMatrix[22][15] = 120;
    this->mainMatrix[22][16] = FOOD;
    this->mainMatrix[22][17] = FOOD;
    this->mainMatrix[22][18] = 121;
    this->mainMatrix[22][19] = FOOD;
    this->mainMatrix[22][20] = FOOD;
    this->mainMatrix[22][21] = 122;
    this->mainMatrix[22][22] = MU;
    this->mainMatrix[22][23] = MU;
    this->mainMatrix[22][24] = 123;
    this->mainMatrix[22][25] = EMPTY;
    this->mainMatrix[22][26] = EMPTY;
    this->mainMatrix[22][27] = EMPTY;

    this->mainMatrix[21][0] = MNW;
    this->mainMatrix[21][1] = MD;
    this->mainMatrix[21][2] = MNE;
    this->mainMatrix[21][3] = FOOD;
    this->mainMatrix[21][4] = MU;
    this->mainMatrix[21][5] = MSW;
    this->mainMatrix[21][6] = MD;
    this->mainMatrix[21][7] = MD;
    this->mainMatrix[21][8] = MNE;
    this->mainMatrix[21][9] = EMPTY;
    this->mainMatrix[21][10] = MNW;
    this->mainMatrix[21][11] = MD;
    this->mainMatrix[21][12] = MD;
    this->mainMatrix[21][13] = MSE;
    this->mainMatrix[21][14] = MSW;
    this->mainMatrix[21][15] = MD;
    this->mainMatrix[21][16] = MD;
    this->mainMatrix[21][17] = MNE;
    this->mainMatrix[21][18] = EMPTY;
    this->mainMatrix[21][19] = MNW;
    this->mainMatrix[21][20] = MD;
    this->mainMatrix[21][21] = MD ;
    this->mainMatrix[21][22] = MSE;
    this->mainMatrix[21][23] = MU;
    this->mainMatrix[21][24] = FOOD;
    this->mainMatrix[21][25] = MNW;
    this->mainMatrix[21][26] = MD;
    this->mainMatrix[21][27] = MNE;

    this->mainMatrix[20][0] = MU;
    this->mainMatrix[20][1] = WALL;
    this->mainMatrix[20][2] = MU;
    this->mainMatrix[20][3] = FOOD;
    this->mainMatrix[20][4] = MSW;
    this->mainMatrix[20][5] = MD;
    this->mainMatrix[20][6] = MD;
    this->mainMatrix[20][7] = MD;
    this->mainMatrix[20][8] = MSE;
    this->mainMatrix[20][9] = EMPTY;
    this->mainMatrix[20][10] = MSW;
    this->mainMatrix[20][11] = MD;
    this->mainMatrix[20][12] = MD;
    this->mainMatrix[20][13] = MD;
    this->mainMatrix[20][14] = MD;
    this->mainMatrix[20][15] = MD;
    this->mainMatrix[20][16] = MD;
    this->mainMatrix[20][17] = MSE;
    this->mainMatrix[20][18] = EMPTY;
    this->mainMatrix[20][19] = MSW;
    this->mainMatrix[20][20] = MD;
    this->mainMatrix[20][21] = MD ;
    this->mainMatrix[20][22] = MD;
    this->mainMatrix[20][23] = MSE;
    this->mainMatrix[20][24] = FOOD;
    this->mainMatrix[20][25] = MU;
    this->mainMatrix[20][26] = WALL;
    this->mainMatrix[20][27] = MU;

    this->mainMatrix[19][0] = MU;
    this->mainMatrix[19][1] = WALL;
    this->mainMatrix[19][2] = MU;
    this->mainMatrix[19][3] = 124;
    this->mainMatrix[19][4] = EMPTY;
    this->mainMatrix[19][5] = EMPTY;
    this->mainMatrix[19][6] = EMPTY;
    this->mainMatrix[19][7] = EMPTY;
    this->mainMatrix[19][8] = EMPTY;
    this->mainMatrix[19][9] = 225;
    this->mainMatrix[19][10] = EMPTY;
    this->mainMatrix[19][11] = EMPTY;
    this->mainMatrix[19][12] = EMPTY;
    this->mainMatrix[19][13] = EMPTY;
    this->mainMatrix[19][14] = EMPTY;
    this->mainMatrix[19][15] = EMPTY;
    this->mainMatrix[19][16] = EMPTY;
    this->mainMatrix[19][17] = EMPTY;
    this->mainMatrix[19][18] = 226;
    this->mainMatrix[19][19] = EMPTY;
    this->mainMatrix[19][20] = EMPTY;
    this->mainMatrix[19][21] = EMPTY;
    this->mainMatrix[19][22] = EMPTY;
    this->mainMatrix[19][23] = EMPTY;
    this->mainMatrix[19][24] = 127;
    this->mainMatrix[19][25] = MU;
    this->mainMatrix[19][26] = WALL;
    this->mainMatrix[19][27] = MU;

    this->mainMatrix[18][0] = MU;
    this->mainMatrix[18][1] = WALL;
    this->mainMatrix[18][2] = MU;
    this->mainMatrix[18][3] = FOOD;
    this->mainMatrix[18][4] = MNW;
    this->mainMatrix[18][5] = MD;
    this->mainMatrix[18][6] = MD;
    this->mainMatrix[18][7] = MD;
    this->mainMatrix[18][8] = MNE;
    this->mainMatrix[18][9] = EMPTY;
    this->mainMatrix[18][10] = MNW;
    this->mainMatrix[18][11] = MCN;
    this->mainMatrix[18][12] = MD;
    this->mainMatrix[18][13] = DOOR;
    this->mainMatrix[18][14] = DOOR;
    this->mainMatrix[18][15] = MD;
    this->mainMatrix[18][16] = MCN;
    this->mainMatrix[18][17] = MNE;
    this->mainMatrix[18][18] = EMPTY;
    this->mainMatrix[18][19] = MNW;
    this->mainMatrix[18][20] = MD;
    this->mainMatrix[18][21] = MD;
    this->mainMatrix[18][22] = MD;
    this->mainMatrix[18][23] = MNE;
    this->mainMatrix[18][24] = FOOD;
    this->mainMatrix[18][25] = MU;
    this->mainMatrix[18][26] = WALL;
    this->mainMatrix[18][27] = MU;

    this->mainMatrix[17][0] = MU;
    this->mainMatrix[17][1] = WALL;
    this->mainMatrix[17][2] = MU;
    this->mainMatrix[17][3] = FOOD;
    this->mainMatrix[17][4] = MU;
    this->mainMatrix[17][5] = MNW;
    this->mainMatrix[17][6] = MD;
    this->mainMatrix[17][7] = MD;
    this->mainMatrix[17][8] = MSE;
    this->mainMatrix[17][9] = EMPTY;
    this->mainMatrix[17][10] = MU;
    this->mainMatrix[17][11] = MU;
    this->mainMatrix[17][12] = EMPTY;
    this->mainMatrix[17][13] = EMPTY;
    this->mainMatrix[17][14] = EMPTY;
    this->mainMatrix[17][15] = EMPTY;
    this->mainMatrix[17][16] = MU;
    this->mainMatrix[17][17] = MU;
    this->mainMatrix[17][18] = EMPTY;
    this->mainMatrix[17][19] = MSW;
    this->mainMatrix[17][20] = MD;
    this->mainMatrix[17][21] = MD;
    this->mainMatrix[17][22] = MNE;
    this->mainMatrix[17][23] = MU;
    this->mainMatrix[17][24] = FOOD;
    this->mainMatrix[17][25] = MU;
    this->mainMatrix[17][26] = WALL;
    this->mainMatrix[17][27] = MU;

    this->mainMatrix[16][0] = MU;
    this->mainMatrix[16][1] = WALL;
    this->mainMatrix[16][2] = MU;
    this->mainMatrix[16][3] = FOOD;
    this->mainMatrix[16][4] = MU;
    this->mainMatrix[16][5] = MU;
    this->mainMatrix[16][6] = 228;
    this->mainMatrix[16][7] = EMPTY;
    this->mainMatrix[16][8] = EMPTY;
    this->mainMatrix[16][9] = 229;
    this->mainMatrix[16][10] = MU;
    this->mainMatrix[16][11] = MU;
    this->mainMatrix[16][12] = EMPTY;
    this->mainMatrix[16][13] = EMPTY;
    this->mainMatrix[16][14] = EMPTY;
    this->mainMatrix[16][15] = EMPTY;
    this->mainMatrix[16][16] = MU;
    this->mainMatrix[16][17] = MU;
    this->mainMatrix[16][18] = 230;
    this->mainMatrix[16][19] = EMPTY;
    this->mainMatrix[16][20] = EMPTY;
    this->mainMatrix[16][21] = 231;
    this->mainMatrix[16][22] = MU;
    this->mainMatrix[16][23] = MU;
    this->mainMatrix[16][24] = FOOD;
    this->mainMatrix[16][25] = MU;
    this->mainMatrix[16][26] = WALL;
    this->mainMatrix[16][27] = MU;

    this->mainMatrix[15][0] = MU;
    this->mainMatrix[15][1] = WALL;
    this->mainMatrix[15][2] = MU;
    this->mainMatrix[15][3] = FOOD;
    this->mainMatrix[15][4] = MU;
    this->mainMatrix[15][5] = MU;
    this->mainMatrix[15][6] = EMPTY;
    this->mainMatrix[15][7] = MNW;
    this->mainMatrix[15][8] = MNE;
    this->mainMatrix[15][9] = EMPTY;
    this->mainMatrix[15][10] = MU;
    this->mainMatrix[15][11] = MSW;
    this->mainMatrix[15][12] = MD;
    this->mainMatrix[15][13] = MD;
    this->mainMatrix[15][14] = MD;
    this->mainMatrix[15][15] = MD;
    this->mainMatrix[15][16] = MSE;
    this->mainMatrix[15][17] = MU;
    this->mainMatrix[15][18] = EMPTY;
    this->mainMatrix[15][19] = MNW;
    this->mainMatrix[15][20] = MNE;
    this->mainMatrix[15][21] = EMPTY;
    this->mainMatrix[15][22] = MU;
    this->mainMatrix[15][23] = MU;
    this->mainMatrix[15][24] = FOOD;
    this->mainMatrix[15][25] = MU;
    this->mainMatrix[15][26] = WALL;
    this->mainMatrix[15][27] = MU;

    this->mainMatrix[14][0] = MSW;
    this->mainMatrix[14][1] = MD;
    this->mainMatrix[14][2] = MSE;
    this->mainMatrix[14][3] = FOOD;
    this->mainMatrix[14][4] = MSW;
    this->mainMatrix[14][5] = MSE;
    this->mainMatrix[14][6] = EMPTY;
    this->mainMatrix[14][7] = MU;
    this->mainMatrix[14][8] = MU;
    this->mainMatrix[14][9] = EMPTY;
    this->mainMatrix[14][10] = MSW;
    this->mainMatrix[14][11] = MD;
    this->mainMatrix[14][12] = MD;
    this->mainMatrix[14][13] = MD;
    this->mainMatrix[14][14] = MD;
    this->mainMatrix[14][15] = MD;
    this->mainMatrix[14][16] = MD;
    this->mainMatrix[14][17] = MSE;
    this->mainMatrix[14][18] = EMPTY;
    this->mainMatrix[14][19] = MU;
    this->mainMatrix[14][20] = MU;
    this->mainMatrix[14][21] = EMPTY;
    this->mainMatrix[14][22] = MSW;
    this->mainMatrix[14][23] = MSE;
    this->mainMatrix[14][24] = FOOD;
    this->mainMatrix[14][25] = MSW;
    this->mainMatrix[14][26] = MD;
    this->mainMatrix[14][27] = MSE;

    this->mainMatrix[13][0] = EMPTY;
    this->mainMatrix[13][1] = EMPTY;
    this->mainMatrix[13][2] = EMPTY;
    this->mainMatrix[13][3] = 132;
    this->mainMatrix[13][4] = EMPTY;
    this->mainMatrix[13][5] = EMPTY;
    this->mainMatrix[13][6] = 233;
    this->mainMatrix[13][7] = MU;
    this->mainMatrix[13][8] = MU;
    this->mainMatrix[13][9] = 234;
    this->mainMatrix[13][10] = EMPTY;
    this->mainMatrix[13][11] = EMPTY;
    this->mainMatrix[13][12] = 235;
    this->mainMatrix[13][13] = EMPTY;
    this->mainMatrix[13][14] = EMPTY;
    this->mainMatrix[13][15] = 236;
    this->mainMatrix[13][16] = EMPTY;
    this->mainMatrix[13][17] = EMPTY;
    this->mainMatrix[13][18] = 237;
    this->mainMatrix[13][19] = MU;
    this->mainMatrix[13][20] = MU;
    this->mainMatrix[13][21] = 238;
    this->mainMatrix[13][22] = EMPTY;
    this->mainMatrix[13][23] = EMPTY;
    this->mainMatrix[13][24] = 139;
    this->mainMatrix[13][25] = EMPTY;
    this->mainMatrix[13][26] = EMPTY;
    this->mainMatrix[13][27] = EMPTY;

    this->mainMatrix[12][0] = MNW;
    this->mainMatrix[12][1] = MD;
    this->mainMatrix[12][2] = MNE;
    this->mainMatrix[12][3] = FOOD;
    this->mainMatrix[12][4] = MNW;
    this->mainMatrix[12][5] = MD;
    this->mainMatrix[12][6] = MD;
    this->mainMatrix[12][7] = MSE;
    this->mainMatrix[12][8] = MSW;
    this->mainMatrix[12][9] = MD;
    this->mainMatrix[12][10] = MD;
    this->mainMatrix[12][11] = MNE;
    this->mainMatrix[12][12] = EMPTY;
    this->mainMatrix[12][13] = MNW;
    this->mainMatrix[12][14] = MNE;
    this->mainMatrix[12][15] = EMPTY;
    this->mainMatrix[12][16] = MNW;
    this->mainMatrix[12][17] = MD;
    this->mainMatrix[12][18] = MD;
    this->mainMatrix[12][19] = MSE;
    this->mainMatrix[12][20] = MSW;
    this->mainMatrix[12][21] = MD;
    this->mainMatrix[12][22] = MD;
    this->mainMatrix[12][23] = MNE;
    this->mainMatrix[12][24] = FOOD;
    this->mainMatrix[12][25] = MNW;
    this->mainMatrix[12][26] = MD;
    this->mainMatrix[12][27] = MNE;

    this->mainMatrix[11][0] = MU;
    this->mainMatrix[11][1] = WALL;
    this->mainMatrix[11][2] = MU;
    this->mainMatrix[11][3] = FOOD;
    this->mainMatrix[11][4] = MSW;
    this->mainMatrix[11][5] = MD;
    this->mainMatrix[11][6] = MD;
    this->mainMatrix[11][7] = MD;
    this->mainMatrix[11][8] = MD;
    this->mainMatrix[11][9] = MD;
    this->mainMatrix[11][10] = MD;
    this->mainMatrix[11][11] = MSE;
    this->mainMatrix[11][12] = EMPTY;
    this->mainMatrix[11][13] = MU;
    this->mainMatrix[11][14] = MU;
    this->mainMatrix[11][15] = EMPTY;
    this->mainMatrix[11][16] = MSW;
    this->mainMatrix[11][17] = MD;
    this->mainMatrix[11][18] = MD;
    this->mainMatrix[11][19] = MD;
    this->mainMatrix[11][20] = MD;
    this->mainMatrix[11][21] = MD;
    this->mainMatrix[11][22] = MD;
    this->mainMatrix[11][23] = MSE;
    this->mainMatrix[11][24] = FOOD;
    this->mainMatrix[11][25] = MU;
    this->mainMatrix[11][26] = WALL;
    this->mainMatrix[11][27] = MU;

    this->mainMatrix[10][0] = MU;
    this->mainMatrix[10][1] = WALL;
    this->mainMatrix[10][2] = MU;
    this->mainMatrix[10][3] = 140;
    this->mainMatrix[10][4] = FOOD;
    this->mainMatrix[10][5] = FOOD;
    this->mainMatrix[10][6] = FOOD;
    this->mainMatrix[10][7] = FOOD;
    this->mainMatrix[10][8] = FOOD;
    this->mainMatrix[10][9] = 141;
    this->mainMatrix[10][10] = EMPTY;
    this->mainMatrix[10][11] = EMPTY;
    this->mainMatrix[10][12] = 242;
    this->mainMatrix[10][13] = MU;
    this->mainMatrix[10][14] = MU;
    this->mainMatrix[10][15] = 243;
    this->mainMatrix[10][16] = EMPTY;
    this->mainMatrix[10][17] = EMPTY;
    this->mainMatrix[10][18] = 144;
    this->mainMatrix[10][19] = FOOD;
    this->mainMatrix[10][20] = FOOD;
    this->mainMatrix[10][21] = FOOD;
    this->mainMatrix[10][22] = FOOD;
    this->mainMatrix[10][23] = FOOD;
    this->mainMatrix[10][24] = 145;
    this->mainMatrix[10][25] = MU;
    this->mainMatrix[10][26] = WALL;
    this->mainMatrix[10][27] = MU;

    this->mainMatrix[9][0] = MU;
    this->mainMatrix[9][1] = WALL;
    this->mainMatrix[9][2] = MU;
    this->mainMatrix[9][3] = FOOD;
    this->mainMatrix[9][4] = MNW;
    this->mainMatrix[9][5] = MD;
    this->mainMatrix[9][6] = MD;
    this->mainMatrix[9][7] = MD;
    this->mainMatrix[9][8] = MNE;
    this->mainMatrix[9][9] = FOOD;
    this->mainMatrix[9][10] = MNW;
    this->mainMatrix[9][11] = MD;
    this->mainMatrix[9][12] = MD;
    this->mainMatrix[9][13] = MSE;
    this->mainMatrix[9][14] = MSW;
    this->mainMatrix[9][15] = MD;
    this->mainMatrix[9][16] = MD;
    this->mainMatrix[9][17] = MNE;
    this->mainMatrix[9][18] = FOOD;
    this->mainMatrix[9][19] = MNW;
    this->mainMatrix[9][20] = MD;
    this->mainMatrix[9][21] = MD;
    this->mainMatrix[9][22] = MD;
    this->mainMatrix[9][23] = MNE;
    this->mainMatrix[9][24] = FOOD;
    this->mainMatrix[9][25] = MU;
    this->mainMatrix[9][26] = WALL;
    this->mainMatrix[9][27] = MU;

    this->mainMatrix[8][0] = MCW;
    this->mainMatrix[8][1] = MD;
    this->mainMatrix[8][2] = MSE;
    this->mainMatrix[8][3] = FOOD;
    this->mainMatrix[8][4] = MSW;
    this->mainMatrix[8][5] = MD;
    this->mainMatrix[8][6] = MD;
    this->mainMatrix[8][7] = MD;
    this->mainMatrix[8][8] = MSE;
    this->mainMatrix[8][9] = FOOD;
    this->mainMatrix[8][10] = MSW;
    this->mainMatrix[8][11] = MD;
    this->mainMatrix[8][12] = MD;
    this->mainMatrix[8][13] = MD;
    this->mainMatrix[8][14] = MD;
    this->mainMatrix[8][15] = MD;
    this->mainMatrix[8][16] = MD;
    this->mainMatrix[8][17] = MSE;
    this->mainMatrix[8][18] = FOOD;
    this->mainMatrix[8][19] = MSW;
    this->mainMatrix[8][20] = MD;
    this->mainMatrix[8][21] = MD;
    this->mainMatrix[8][22] = MD;
    this->mainMatrix[8][23] = MSE;
    this->mainMatrix[8][24] = FOOD;
    this->mainMatrix[8][25] = MSW;
    this->mainMatrix[8][26] = MD;
    this->mainMatrix[8][27] = MCE;

    this->mainMatrix[7][0] = MU;
    this->mainMatrix[7][1] = 146;
    this->mainMatrix[7][2] = FOOD;
    this->mainMatrix[7][3] = 147;
    this->mainMatrix[7][4] = FOOD;
    this->mainMatrix[7][5] = FOOD;
    this->mainMatrix[7][6] = 148;
    this->mainMatrix[7][7] = FOOD;
    this->mainMatrix[7][8] = FOOD;
    this->mainMatrix[7][9] = 149;
    this->mainMatrix[7][10] = FOOD;
    this->mainMatrix[7][11] = FOOD;
    this->mainMatrix[7][12] = 150;
    this->mainMatrix[7][13] = FOOD;
    this->mainMatrix[7][14] = FOOD;
    this->mainMatrix[7][15] = 151;
    this->mainMatrix[7][16] = FOOD;
    this->mainMatrix[7][17] = FOOD;
    this->mainMatrix[7][18] = 152;
    this->mainMatrix[7][19] = FOOD;
    this->mainMatrix[7][20] = FOOD;
    this->mainMatrix[7][21] = 153;
    this->mainMatrix[7][22] = FOOD;
    this->mainMatrix[7][23] = FOOD;
    this->mainMatrix[7][24] = 154;
    this->mainMatrix[7][25] = FOOD;
    this->mainMatrix[7][26] = 155;
    this->mainMatrix[7][27] = MU;

    this->mainMatrix[6][0] = MU;
    this->mainMatrix[6][1] = FOOD;
    this->mainMatrix[6][2] = MNW;
    this->mainMatrix[6][3] = MD;
    this->mainMatrix[6][4] = MD;
    this->mainMatrix[6][5] = MNE;
    this->mainMatrix[6][6] = FOOD;
    this->mainMatrix[6][7] = MNW;
    this->mainMatrix[6][8] = MD;
    this->mainMatrix[6][9] = MD;
    this->mainMatrix[6][10] = MD;
    this->mainMatrix[6][11] = MNE;
    this->mainMatrix[6][12] = FOOD;
    this->mainMatrix[6][13] = MNW;
    this->mainMatrix[6][14] = MNE;
    this->mainMatrix[6][15] = FOOD;
    this->mainMatrix[6][16] = MNW;
    this->mainMatrix[6][17] = MD;
    this->mainMatrix[6][18] = MD;
    this->mainMatrix[6][19] = MD;
    this->mainMatrix[6][20] = MNE;
    this->mainMatrix[6][21] = FOOD;
    this->mainMatrix[6][22] = MNW;
    this->mainMatrix[6][23] = MD;
    this->mainMatrix[6][24] = MD;
    this->mainMatrix[6][25] = MNE;
    this->mainMatrix[6][26] = FOOD;
    this->mainMatrix[6][27] = MU;

    this->mainMatrix[5][0] = MU;
    this->mainMatrix[5][1] = FOOD;
    this->mainMatrix[5][2] = MU;
    this->mainMatrix[5][3] = WALL;
    this->mainMatrix[5][4] = WALL;
    this->mainMatrix[5][5] = MU;
    this->mainMatrix[5][6] = FOOD;
    this->mainMatrix[5][7] = MU;
    this->mainMatrix[5][8] = MNW;
    this->mainMatrix[5][9] = MD;
    this->mainMatrix[5][10] = MD;
    this->mainMatrix[5][11] = MSE;
    this->mainMatrix[5][12] = FOOD;
    this->mainMatrix[5][13] = MU;
    this->mainMatrix[5][14] = MU;
    this->mainMatrix[5][15] = FOOD;
    this->mainMatrix[5][16] = MSW;
    this->mainMatrix[5][17] = MD;
    this->mainMatrix[5][18] = MD;
    this->mainMatrix[5][19] = MNE;
    this->mainMatrix[5][20] = MU;
    this->mainMatrix[5][21] = FOOD;
    this->mainMatrix[5][22] = MU;
    this->mainMatrix[5][23] = WALL;
    this->mainMatrix[5][24] = WALL;
    this->mainMatrix[5][25] = MU;
    this->mainMatrix[5][26] = FOOD;
    this->mainMatrix[5][27] = MU;

    this->mainMatrix[4][0] = MU;
    this->mainMatrix[4][1] = FOOD;
    this->mainMatrix[4][2] = MU;
    this->mainMatrix[4][3] = WALL;
    this->mainMatrix[4][4] = WALL;
    this->mainMatrix[4][5] = MU;
    this->mainMatrix[4][6] = FOOD;
    this->mainMatrix[4][7] = MU;
    this->mainMatrix[4][8] = MU;
    this->mainMatrix[4][9] = 156;
    this->mainMatrix[4][10] = FOOD;
    this->mainMatrix[4][11] = FOOD;
    this->mainMatrix[4][12] = 157;
    this->mainMatrix[4][13] = MU;
    this->mainMatrix[4][14] = MU;
    this->mainMatrix[4][15] = 158;
    this->mainMatrix[4][16] = FOOD;
    this->mainMatrix[4][17] = FOOD;
    this->mainMatrix[4][18] = 159;
    this->mainMatrix[4][19] = MU;
    this->mainMatrix[4][20] = MU;
    this->mainMatrix[4][21] = FOOD;
    this->mainMatrix[4][22] = MU;
    this->mainMatrix[4][23] = WALL;
    this->mainMatrix[4][24] = WALL;
    this->mainMatrix[4][25] = MU;
    this->mainMatrix[4][26] = FOOD;
    this->mainMatrix[4][27] = MU;

    this->mainMatrix[3][0] = MU;
    this->mainMatrix[3][1] = SPECIALFOOD;
    this->mainMatrix[3][2] = MU;
    this->mainMatrix[3][3] = WALL;
    this->mainMatrix[3][4] = WALL;
    this->mainMatrix[3][5] = MU;
    this->mainMatrix[3][6] = FOOD;
    this->mainMatrix[3][7] = MU;
    this->mainMatrix[3][8] = MU;
    this->mainMatrix[3][9] = FOOD;
    this->mainMatrix[3][10] = MNW;
    this->mainMatrix[3][11] = MD;
    this->mainMatrix[3][12] = MD;
    this->mainMatrix[3][13] = MSE;
    this->mainMatrix[3][14] = MSW;
    this->mainMatrix[3][15] = MD;
    this->mainMatrix[3][16] = MD;
    this->mainMatrix[3][17] = MNE;
    this->mainMatrix[3][18] = FOOD;
    this->mainMatrix[3][19] = MU;
    this->mainMatrix[3][20] = MU;
    this->mainMatrix[3][21] = FOOD;
    this->mainMatrix[3][22] = MU;
    this->mainMatrix[3][23] = WALL;
    this->mainMatrix[3][24] = WALL;
    this->mainMatrix[3][25] = MU;
    this->mainMatrix[3][26] = SPECIALFOOD;
    this->mainMatrix[3][27] = MU;

    this->mainMatrix[2][0] = MU;
    this->mainMatrix[2][1] = FOOD;
    this->mainMatrix[2][2] = MSW;
    this->mainMatrix[2][3] = MD;
    this->mainMatrix[2][4] = MD;
    this->mainMatrix[2][5] = MSE;
    this->mainMatrix[2][6] = FOOD;
    this->mainMatrix[2][7] = MSW;
    this->mainMatrix[2][8] = MSE;
    this->mainMatrix[2][9] = FOOD;
    this->mainMatrix[2][10] = MSW;
    this->mainMatrix[2][11] = MD;
    this->mainMatrix[2][12] = MD;
    this->mainMatrix[2][13] = MD;
    this->mainMatrix[2][14] = MD;
    this->mainMatrix[2][15] = MD;
    this->mainMatrix[2][16] = MD;
    this->mainMatrix[2][17] = MSE;
    this->mainMatrix[2][18] = FOOD;
    this->mainMatrix[2][19] = MSW;
    this->mainMatrix[2][20] = MSE;
    this->mainMatrix[2][21] = FOOD;
    this->mainMatrix[2][22] = MSW;
    this->mainMatrix[2][23] = MD;
    this->mainMatrix[2][24] = MD;
    this->mainMatrix[2][25] = MSE;
    this->mainMatrix[2][26] = FOOD;
    this->mainMatrix[2][27] = MU;

    this->mainMatrix[1][0] = MU;
    this->mainMatrix[1][1] = 160;
    this->mainMatrix[1][2] = FOOD;
    this->mainMatrix[1][3] = FOOD;
    this->mainMatrix[1][4] = FOOD;
    this->mainMatrix[1][5] = FOOD;
    this->mainMatrix[1][6] = 161;
    this->mainMatrix[1][7] = FOOD;
    this->mainMatrix[1][8] = FOOD;
    this->mainMatrix[1][9] = 162;
    this->mainMatrix[1][10] = FOOD;
    this->mainMatrix[1][11] = FOOD;
    this->mainMatrix[1][12] = FOOD;
    this->mainMatrix[1][13] = FOOD;
    this->mainMatrix[1][14] = FOOD;
    this->mainMatrix[1][15] = FOOD;
    this->mainMatrix[1][16] = FOOD;
    this->mainMatrix[1][17] = FOOD;
    this->mainMatrix[1][18] = 163;
    this->mainMatrix[1][19] = FOOD;
    this->mainMatrix[1][20] = FOOD;
    this->mainMatrix[1][21] = 164;
    this->mainMatrix[1][22] = FOOD;
    this->mainMatrix[1][23] = FOOD;
    this->mainMatrix[1][24] = FOOD;
    this->mainMatrix[1][25] = FOOD;
    this->mainMatrix[1][26] = 165;
    this->mainMatrix[1][27] = MU;

    this->mainMatrix[0][0] = MSW;
    this->mainMatrix[0][1] = MD;
    this->mainMatrix[0][2] = MD;
    this->mainMatrix[0][3] = MD;
    this->mainMatrix[0][4] = MD;
    this->mainMatrix[0][5] = MD;
    this->mainMatrix[0][6] = MD;
    this->mainMatrix[0][7] = MD;
    this->mainMatrix[0][8] = MD;
    this->mainMatrix[0][9] = MD;
    this->mainMatrix[0][10] = MD;
    this->mainMatrix[0][11] = MD;
    this->mainMatrix[0][12] = MD;
    this->mainMatrix[0][13] = MD;
    this->mainMatrix[0][14] = MD;
    this->mainMatrix[0][15] = MD;
    this->mainMatrix[0][16] = MD;
    this->mainMatrix[0][17] = MD;
    this->mainMatrix[0][18] = MD;
    this->mainMatrix[0][19] = MD;
    this->mainMatrix[0][20] = MD;
    this->mainMatrix[0][21] = MD;
    this->mainMatrix[0][22] = MD;
    this->mainMatrix[0][23] = MD;
    this->mainMatrix[0][24] = MD;
    this->mainMatrix[0][25] = MD;
    this->mainMatrix[0][26] = MD;
    this->mainMatrix[0][27] = MSE;
}
void Scenario::drawMatrix()
{
    Vector startPosition = *new Vector(this->startPositionX, this->startPositionY, 0.0f);
    Square cell = *new Square(startPosition, cellSize);

    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < 28; j++)
        {
            cell.move(startPosition);
            if(this->mainMatrix[i][j] < 100)
                cell.drawSquareTexture(textureSet, this->mainMatrix[i][j]);
            else if(this->mainMatrix[i][j] < 200)
                cell.drawSquareTexture(textureSet, FOOD);
            else
                cell.drawSquareTexture(textureSet, EMPTY);

            startPosition.setCoordinates(startPosition[0] + this->cellSize, startPosition[1], startPosition[2]);
        }
        startPosition.setCoordinates(-3.0f, startPosition[1], startPosition[2]);
        startPosition.setCoordinates(startPosition[0], startPosition[1] + this->cellSize, startPosition[2]);
    }

    delete &cell;
    delete &startPosition;
}

void Scenario::buildDistanceMatrix()
{
    for(int i = 0; i < 68; i++)
    {
        for(int j = 0; j < 68; j++)
        {
            distanceMatrix[i][j] = -1;
        }
    }

    distanceMatrix[0][1] = distanceMatrix[1][0] = 5;
    distanceMatrix[0][6] = distanceMatrix[6][0] = 3;
    distanceMatrix[6][7] = distanceMatrix[7][6] = 2;
    distanceMatrix[7][8] = distanceMatrix[8][7] = 3;
    distanceMatrix[1][8] = distanceMatrix[8][1] = 3;
    distanceMatrix[8][9] = distanceMatrix[9][8] = 3;
    distanceMatrix[9][2] = distanceMatrix[2][9] = 3;
    distanceMatrix[2][3] = distanceMatrix[3][2] = 9;
    distanceMatrix[3][12] = distanceMatrix[12][3] = 3;
    distanceMatrix[4][5] = distanceMatrix[5][4] = 5;
    distanceMatrix[4][13] = distanceMatrix[13][4] = 3;
    distanceMatrix[5][15] = distanceMatrix[15][5] = 3;
    distanceMatrix[9][10] = distanceMatrix[10][9] = 3;
    distanceMatrix[10][11] = distanceMatrix[11][10] = 3;
    distanceMatrix[11][12] = distanceMatrix[12][11] = 3;
    distanceMatrix[12][13] = distanceMatrix[13][12] = 3;
    distanceMatrix[13][14] = distanceMatrix[14][13] = 3;
    distanceMatrix[14][15] = distanceMatrix[15][14] = 2;
    distanceMatrix[7][16] = distanceMatrix[16][7] = 4;
    distanceMatrix[8][17] = distanceMatrix[17][8] = 4;
    distanceMatrix[10][19] = distanceMatrix[19][10] = 4;
    distanceMatrix[11][20] = distanceMatrix[20][11] = 4;
    distanceMatrix[13][22] = distanceMatrix[22][13] = 4;
    distanceMatrix[14][23] = distanceMatrix[23][14] = 4;
    distanceMatrix[16][24] = distanceMatrix[24][16] = 3;
    distanceMatrix[17][18] = distanceMatrix[18][17] = 3;
    distanceMatrix[18][25] = distanceMatrix[25][18] = 3;
    distanceMatrix[18][19] = distanceMatrix[19][18] = 3;
    distanceMatrix[20][21] = distanceMatrix[21][20] = 3;
    distanceMatrix[21][22] = distanceMatrix[22][21] = 3;
    distanceMatrix[21][26] = distanceMatrix[26][21] = 3;
    distanceMatrix[23][27] = distanceMatrix[27][23] = 3;
    distanceMatrix[23][16] = distanceMatrix[16][23] = 4;
    distanceMatrix[24][25] = distanceMatrix[25][24] = 6;
    distanceMatrix[24][32] = distanceMatrix[32][24] = 6;
    distanceMatrix[25][26] = distanceMatrix[26][25] = 9;
    distanceMatrix[25][29] = distanceMatrix[29][25] = 3;
    distanceMatrix[26][27] = distanceMatrix[27][26] = 6;
    distanceMatrix[26][30] = distanceMatrix[30][26] = 3;
    distanceMatrix[27][39] = distanceMatrix[39][27] = 6;
    distanceMatrix[28][29] = distanceMatrix[29][28] = 3;
    distanceMatrix[30][31] = distanceMatrix[31][30] = 3;
    distanceMatrix[28][33] = distanceMatrix[33][28] = 3;
    distanceMatrix[29][34] = distanceMatrix[34][29] = 3;
    distanceMatrix[30][37] = distanceMatrix[37][30] = 3;
    distanceMatrix[31][38] = distanceMatrix[38][31] = 3;
    distanceMatrix[32][33] = distanceMatrix[33][32] = 3;
    distanceMatrix[32][40] = distanceMatrix[40][32] = 3;
    distanceMatrix[34][35] = distanceMatrix[35][34] = 3;
    distanceMatrix[35][42] = distanceMatrix[42][35] = 3;
    distanceMatrix[35][36] = distanceMatrix[36][35] = 3;
    distanceMatrix[36][37] = distanceMatrix[37][36] = 3;
    distanceMatrix[36][43] = distanceMatrix[43][36] = 3;
    distanceMatrix[38][39] = distanceMatrix[39][38] = 3;
    distanceMatrix[39][45] = distanceMatrix[45][39] = 3;
    distanceMatrix[40][47] = distanceMatrix[47][40] = 3;
    distanceMatrix[40][41] = distanceMatrix[41][40] = 6;
    distanceMatrix[41][49] = distanceMatrix[49][41] = 3;
    distanceMatrix[41][42] = distanceMatrix[42][41] = 3;
    distanceMatrix[43][44] = distanceMatrix[44][43] = 3;
    distanceMatrix[44][52] = distanceMatrix[52][44] = 3;
    distanceMatrix[44][45] = distanceMatrix[45][44] = 6;
    distanceMatrix[45][54] = distanceMatrix[54][45] = 3;
    distanceMatrix[45][40] = distanceMatrix[40][45] = 4;
    distanceMatrix[46][47] = distanceMatrix[47][46] = 2;
    distanceMatrix[46][60] = distanceMatrix[60][46] = 6;
    distanceMatrix[47][48] = distanceMatrix[48][47] = 3;
    distanceMatrix[48][49] = distanceMatrix[49][48] = 3;
    distanceMatrix[48][61] = distanceMatrix[61][48] = 6;
    distanceMatrix[49][50] = distanceMatrix[50][49] = 3;
    distanceMatrix[50][57] = distanceMatrix[57][50] = 3;
    distanceMatrix[50][51] = distanceMatrix[51][50] = 3;
    distanceMatrix[51][58] = distanceMatrix[58][51] = 3;
    distanceMatrix[51][52] = distanceMatrix[52][51] = 3;
    distanceMatrix[52][53] = distanceMatrix[53][52] = 3;
    distanceMatrix[53][64] = distanceMatrix[64][53] = 6;
    distanceMatrix[53][54] = distanceMatrix[54][53] = 3;
    distanceMatrix[54][55] = distanceMatrix[55][54] = 2;
    distanceMatrix[55][65] = distanceMatrix[65][55] = 6;
    distanceMatrix[60][61] = distanceMatrix[61][60] = 5;
    distanceMatrix[61][62] = distanceMatrix[62][61] = 3;
    distanceMatrix[62][63] = distanceMatrix[63][62] = 9;
    distanceMatrix[63][64] = distanceMatrix[64][63] = 3;
    distanceMatrix[64][65] = distanceMatrix[65][64] = 5;
    distanceMatrix[56][57] = distanceMatrix[57][56] = 3;
    distanceMatrix[56][62] = distanceMatrix[62][56] = 3;
    distanceMatrix[58][59] = distanceMatrix[59][58] = 3;
    distanceMatrix[59][63] = distanceMatrix[63][59] = 3;
}

int Scenario::getDistanceEdge(int x, int y)
{
    return distanceMatrix[x][y];
}

GLfloat Scenario::getCellSize()
{
    return this->cellSize;
}

GLfloat Scenario::getStartPositionX()
{
    return this->startPositionX;
}

GLfloat Scenario::getStartPositionY()
{
    return this->startPositionY;
}

Texture Scenario::getTextureSet()
{
    return this->textureSet;
}

int Scenario::getValue(int x, int y)
{
    if(x > 0 && x < 28 && y > 0 && y < 30)
        return this->mainMatrix[y][x];
    else if((x == 0 || x == 27) && (y == 13 || y == 22))
        return EMPTY;
    else
        return -1;
}

void Scenario::setValue(int x, int y, int value)
{
    this->mainMatrix[y][x] = value;
}

int Scenario::addNode(int node, int nodeX, int nodeY)
{
    int ix = nodeX, iy = nodeY;
    int existentNode;

    if(getValue(nodeX, nodeY) >= 100)
    {
        return getValue(nodeX, nodeY) - ((int)(getValue(nodeX, nodeY)/100)) * 100;
    }
    else
    {
        iy++;
        while(Scenario::allowed(getValue(ix, iy)))
        {
            if(getValue(ix, iy) >= 100)
            {
                existentNode = getValue(ix, iy) - ((int)(getValue(ix, iy)/100)) * 100;
                distanceMatrix[node][existentNode] = distanceMatrix[existentNode][node] = abs(iy - nodeY);
                break;
            }
            iy++;
        }
        iy = nodeY - 1;
        while(Scenario::allowed(getValue(ix, iy)))
        {
            if(getValue(ix, iy) >= 100)
            {
                existentNode = getValue(ix, iy) - ((int)(getValue(ix, iy)/100)) * 100;
                distanceMatrix[node][existentNode] = distanceMatrix[existentNode][node] = abs(iy - nodeY);
                break;
            }
            iy--;
        }
        iy = nodeY;
        ix = nodeX + 1;
        while(Scenario::allowed(getValue(ix, iy)))
        {
            if(getValue(ix, iy) >= 100)
            {
                existentNode = getValue(ix, iy) - ((int)(getValue(ix, iy)/100)) * 100;
                distanceMatrix[node][existentNode] = distanceMatrix[existentNode][node] = abs(ix - nodeX);
                break;
            }
            ix++;
        }

        iy = nodeY;
        ix = nodeX - 1;
        while(Scenario::allowed(getValue(ix, iy)))
        {
            if(getValue(ix, iy) >= 100)
            {
                existentNode = getValue(ix, iy) - ((int)(getValue(ix, iy)/100)) * 100;
                distanceMatrix[node][existentNode] = distanceMatrix[existentNode][node] = abs(ix - nodeX);
                break;
            }
            ix--;
        }

        return node;
    }
}

void Scenario::graphShortestDistance(int sourceNode, struct tTarget * target, int startDistance)
{
    struct tQueueNode * visited;
    Queue q = * new Queue();
    q.enqueue(sourceNode, startDistance);

    while(q.getQuantity() != 0)
    {
        visited = q.dequeue();
        listVisitedEdges[visited->value] = visited->distance;

        if(visited->value == target->object)
        {
            if(visited->distance < target->distance || target->distance == -1)
            {
                target->distance = visited->distance;
            }
        }
        else
        {
            for(int i = 0; i <= 68; i++)
            {
                if((this->getDistanceEdge(visited->value, i) != -1) && ((listVisitedEdges[i] > visited->distance + getDistanceEdge(visited->value, i)) || (listVisitedEdges[i] == -1)))
                {
                    if((visited->value != i) && (sourceNode != i) && (visited->distance < listVisitedEdges[i] || listVisitedEdges[i] == -1))
                    {
                        q.enqueue(i, visited->distance + getDistanceEdge(visited->value, i));
                    }
                }
            }
        }
    }
}

int Scenario::shortestDistanceCorners(int targetX, int targetY, int sourceX, int sourceY)
{
    struct tTarget * target = (struct tTarget *) malloc(sizeof(struct tTarget));
    int sourceNode = addNode(66, sourceX, sourceY);
    target->object = addNode(67, targetX, targetY);
    target->distance = -1;
    target->directionFromSource = -1;
    clearListVisitedEdges();


    graphShortestDistance(sourceNode, target, 0);

    if(sourceNode == 66 || target->object == 67)
    {
        for(int i = 0; i < 68; i++)
        {
            this->distanceMatrix[66][i] = this->distanceMatrix[i][66] = -1;
            this->distanceMatrix[67][i] = this->distanceMatrix[i][67] = -1;
        }
    }

    return target->distance;
}

void Scenario::lookTarget(int x, int y, int direction, int distance, struct tTarget * target, int directionFromSource)
{
    while (Scenario::allowed(getValue(x, y)))
    {
        if(this->lookUpMatrix[x][y] > distance || this->lookUpMatrix[x][y] == -1)
            this->lookUpMatrix[x][y] = distance;
        else
            break;

        if((getValue(x, y) == target->object) || (target->targetX == x && target->targetY == y) || (target->object == FOOD && getValue(x, y) >= 100 && getValue(x, y) < 200))
        {
            if(distance < target->distance || target->distance == -1)
            {
                target->directionFromSource = directionFromSource;
                target->distance = distance;
                target->targetX = x;
                target->targetY = y;
            }
        }

        if(getValue(x, y) >= 100) // Corner
        {
            if(allowed(getValue(x, y + 1)) && direction != 0)
                lookTarget(x, y + 1, 0, distance + 1, target, directionFromSource);
            if(allowed(getValue(x + 1, y)) && direction != 1)
                lookTarget(x + 1, y, 1, distance + 1, target, directionFromSource);
            if(allowed(getValue(x, y - 1)) && direction != 2)
                lookTarget(x, y - 1, 2, distance + 1, target, directionFromSource);
            if(allowed(getValue(x - 1, y)) && direction != 3)
                lookTarget(x - 1, y, 3, distance + 1, target, directionFromSource);
        }

        if((x == 27)&&(y == 13 || y == 22) && direction == 1)
        {
            lookTarget(0, y, 1, distance + 1, target, directionFromSource);
        }
        else if((x == 0) && (y == 13 || y == 22) && direction == 3)
        {
            lookTarget(27, y, 3, distance + 1, target, directionFromSource);
        }

        switch(direction)
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

        distance++;
    }

}

void Scenario::correctTarget(struct tTarget * target)
{
    int x = target->targetX;
    int y = target->targetY;
    int cost = 0;
    int minimumCost = 0;
    int minX = x;
    int minY = y;

    while(!allowed(getValue(x, y)) && y < 30)
    {
        y++;
        cost++;
    }

    minimumCost = cost;
    cost = 0;
    y = target->targetY;

    while(!allowed(getValue(x, y)) && y > 0)
    {
        y--;
        cost++;
    }

    if(cost < minimumCost)
    {
        minX = x;
        minY = y;
        minimumCost = cost;
    }

    cost = 0;
    y = target->targetY;
    x = target->targetX;

    while(!allowed(getValue(x, y)) && x > 0)
    {
        x--;
        cost++;
    }

    if(cost < minimumCost)
    {
        minX = x;
        minY = y;
        minimumCost = cost;
    }

    cost = 0;
    y = target->targetY;
    x = target->targetX;

    while(!allowed(getValue(x, y)) && x < 28)
    {
        x++;
        cost++;
    }

    if(cost < minimumCost)
    {
        minX = x;
        minY = y;
        minimumCost = cost;
    }


    target->targetX = x;
    target->targetY = y;

}

int Scenario::shortestDistanceMaze(int sourceX, int sourceY, int direction, int targetObject, int targetX, int targetY, bool blnDistance)
{
    clearLookupMatrix();
    struct tTarget * target = (struct tTarget *) malloc(sizeof(struct tTarget));
    int x = sourceX;
    int y = sourceY;
    int returnValue;

    target->object = targetObject;
    target->distance = -1;
    target->directionFromSource = -1;
    target->targetX = targetX;
    target->targetY = targetY;

    correctTarget(target);


    this->lookUpMatrix[sourceX][sourceY] = 0;

    if((x == 27)&&(y == 13 || y == 22) && direction == 1)
    {
        lookTarget(0, y, 1, 1, target, 1);
    }
    else if((x == 0) && (y == 13 || y == 22) && direction == 3)
    {
        lookTarget(27, y, 3, 1, target, 3);
    }

    if(allowed(getValue(x, y + 1)))
        lookTarget(x, y + 1, 0, 1, target, 0);
    if(allowed(getValue(x + 1, y)))
        lookTarget(x + 1, y, 1, 1, target, 1);
    if(allowed(getValue(x, y - 1)))
        lookTarget(x, y - 1, 2, 1, target, 2);
    if(allowed(getValue(x - 1, y)))
        lookTarget(x - 1, y, 3, 1, target, 3);

    if(blnDistance)
    {
        if(target->distance != -1)
            returnValue = target->distance;
        else
            returnValue = 9999;
    }
    else
    {
        returnValue = target->directionFromSource;
        if(returnValue == -1)
            returnValue = direction;
    }

    free(target);

    return returnValue;
}

void Scenario::setFruitOnScreen(bool fruitOnScreen)
{
    this->fruitOnScreen = fruitOnScreen;

    if(fruitOnScreen)
    {
        setValue(13, 13, FRUIT1);
    }
    else
        setValue(13, 13, EMPTY);
}

bool Scenario::getFruitOnScreen()
{
    return this->fruitOnScreen;
}
