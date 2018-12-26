#define EMPTY       0
#define FOOD        1
#define SPECIALFOOD 2
#define FRUIT1      3
#define FRUIT2      4
#define FRUIT3      5
#define FRUIT4      6
#define FRUIT5      7
#define FRUIT6      8
#define MD          9
#define MU          10
#define MNW         11
#define MNE         12
#define MSE         13
#define MSW         14
#define MCE         15
#define MCN         16
#define MCS         17
#define MCW         18
#define PACUP1      19
#define PACUP2      20
#define PACUP3      21
#define PACUP4      22
#define PACUP5      23
#define PACRIGHT1   24
#define PACRIGHT2   25
#define PACRIGHT3   26
#define PACRIGHT4   27
#define PACRIGHT5   28
#define PACDOWN1    29
#define PACDOWN2    30
#define PACDOWN3    31
#define PACDOWN4    32
#define PACDOWN5    33
#define PACLEFT1    34
#define PACLEFT2    35
#define PACLEFT3    36
#define PACLEFT4    37
#define PACLEFT5    38
#define MONSTER1U1  39
#define MONSTER1U2  40
#define MONSTER1R1  41
#define MONSTER1R2  42
#define MONSTER1D1  43
#define MONSTER1D2  44
#define MONSTER1L1  45
#define MONSTER1L2  46
#define MONSTER2U1  47
#define MONSTER2U2  48
#define MONSTER2R1  49
#define MONSTER2R2  50
#define MONSTER2D1  51
#define MONSTER2D2  52
#define MONSTER2L1  53
#define MONSTER2L2  54
#define MONSTER3U1  55
#define MONSTER3U2  56
#define MONSTER3R1  57
#define MONSTER3R2  58
#define MONSTER3D1  59
#define MONSTER3D2  60
#define MONSTER3L1  61
#define MONSTER3L2  62
#define MONSTER4U1  63
#define MONSTER4U2  64
#define MONSTER4R1  65
#define MONSTER4R2  66
#define MONSTER4D1  67
#define MONSTER4D2  68
#define MONSTER4L1  69
#define MONSTER4L2  70
#define MONSTER51   71
#define MONSTER52   72
#define MONSTER53   73
#define MONSTER54   74
#define EYEU        75
#define EYER        76
#define EYED        77
#define EYEL        78
#define DOOR        79
#define WALL        80

#include <stdio.h>



class Sprites
{
    private:
            const char * images[81];
            int quantity;

    public:
            Sprites()
            {
                images[0] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Empty.png";
                images[1] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Food.png";
                images[2] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\SpecialFood.png";
                images[3] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Fruit1.png";
                images[4] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Fruit2.png";
                images[5] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Fruit3.png";
                images[6] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Fruit3.png";
                images[7] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Fruit3.png";
                images[8] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Fruit3.png";
                images[9] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MD.png";
                images[10] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MU.png";
                images[11] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MNW.png";
                images[12] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MNE.png";
                images[13] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MSE.png";
                images[14] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MSW.png";
                images[15] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MCE.png";
                images[16] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MCN.png";
                images[17] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MCS.png";
                images[18] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\MCW.png";
                images[19] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacUp1.png";
                images[20] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacUp2.png";
                images[21] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacUp3.png";
                images[22] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacUp4.png";
                images[23] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacUp5.png";
                images[24] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacRight1.png";
                images[25] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacRight2.png";
                images[26] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacRight3.png";
                images[27] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacRight4.png";
                images[28] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacRight5.png";
                images[29] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacDown1.png";
                images[30] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacDown2.png";
                images[31] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacDown3.png";
                images[32] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacDown4.png";
                images[33] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacDown5.png";
                images[34] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacLeft1.png";
                images[35] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacLeft2.png";
                images[36] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacLeft3.png";
                images[37] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacLeft4.png";
                images[38] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\PacLeft5.png";
                images[39] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1U1.png";
                images[40] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1U2.png";
                images[41] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1R1.png";
                images[42] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1R2.png";
                images[43] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1D1.png";
                images[44] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1D2.png";
                images[45] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1L1.png";
                images[46] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster1L2.png";
                images[47] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2U1.png";
                images[48] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2U2.png";
                images[49] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2R1.png";
                images[50] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2R2.png";
                images[51] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2D1.png";
                images[52] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2D2.png";
                images[53] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2L1.png";
                images[54] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster2L2.png";
                images[55] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3U1.png";
                images[56] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3U2.png";
                images[57] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3R1.png";
                images[58] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3R2.png";
                images[59] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3D1.png";
                images[60] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3D2.png";
                images[61] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3L1.png";
                images[62] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster3L2.png";
                images[63] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4U1.png";
                images[64] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4U2.png";
                images[65] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4R1.png";
                images[66] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4R2.png";
                images[67] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4D1.png";
                images[68] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4D2.png";
                images[69] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4L1.png";
                images[70] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster4L2.png";
                images[71] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster51.png";
                images[72] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster52.png";
                images[73] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster53.png";
                images[74] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Monster54.png";
                images[75] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\EyeU.png";
                images[76] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\EyeR.png";
                images[77] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\EyeD.png";
                images[78] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\EyeL.png";
                images[79] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Door.png";
                images[80] = "C:\\Kaiubi\\Development\\Genetic Algorithms\\Pacman\\Images\\Wall.png";

                this->quantity = 81;
            }

            ~Sprites()
            {
                delete[] images;
            }

            const char ** getImages()
            {
                return this->images;
            }

            int getQuantity()
            {
                return this->quantity;
            }
};
