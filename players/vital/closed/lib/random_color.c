#pragma combine_strings
#include <ansi.h>

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
