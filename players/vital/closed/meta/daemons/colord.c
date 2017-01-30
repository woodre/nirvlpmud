/******************************************************************************
 *  File:           colord.c
 *  Function:       Randomly select a color for insertion somewhere
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         02/05/2004
 *  Notes:          black and white are excluded
 *  Change History:
 *****************************************************************************/

#pragma combine_strings
#include <ansi.h>

string
random_color() {
  int x;
  string color;
  x = (random(13)+1);
  switch(x) {
    case 1: color = RED; break;
    case 2: color = YEL; break;
    case 3: color = GRN; break;
    case 4: color = BLU; break;
    case 5: color = CYN; break;
    case 6: color = MAG; break;
    case 7: color = HIR; break;
    case 8: color = HIY; break;
    case 9: color = HIG; break;
    case 10: color = HIB; break;
    case 11: color = HIC; break;
    case 12: color = HIM; break;
    case 13: color = HIW; break;
  }
  return color;
}

string
house_color(string *Houses)
{
    string color;
    int house_bit;

    switch (house_bit)
    {
        case 1  :
            color = CYN;
            break;
        case 2  :
            color = BLU;
            break;
        case 3  :
            color = CYN + BBLU;
            break;
        case 4  :
            color = MAG;
            break;
        case 5  :
            color = MAG + BBLU;
            break;
        case 6  :
            color = MAG + BCYN;
            break;
        case 7  :
            color = GRN + BMAG;
            break;
        case 8  :
            color = YEL;
            break;
        case 9  :
            color = YEL + BCYN;
            break;
        case 10 :
            color = BLU + BYEL;
            break;
        case 11 :
            color = GRN;
            break;
        case 12 :
            color = YEL + BMAG;
            break;
        case 13 :
            color = HIC;
            break;
        case 14 :
            color = HIM;
            break;
        case 15 :
            color = HIM + HBYEL;
            break;
        case 16 :
            color = RED;
            break;
        case 17 :
            color = CYN + BRED;
            break;
        case 18 :
            color = BLU + BRED;
            break;
        case 19 :
            color = HIB + BMAG;
            break;
        case 20 :
            color = RED + BMAG;
            break;
        case 21 :
            color = HIM + BRED;
            break;
        case 22 :
            color = BLU + HBCYN;
            break;
        case 23 :
            color = RED + BYEL;
            break;
        case 24 :
            color = HIR;
            break;
        case 25 :
            color = HIC + BMAG;
            break;
        case 26 :
            color = HIY + BGRN;
            break;
        case 27 :
            color = HIG;
            break;
        case 28 :
            color = HIY + BBLU;
            break;
        case 29 :
            color = HIR + BCYN;
            break;
        case 30 :
            color = HIR + BBLU;
            break;
        case 31 :
            color = HIW;
            break;
    }
    
}