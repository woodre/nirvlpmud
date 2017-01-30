#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "/players/zeus/museum/OBJ/battle_axe.c";

int MobWield, BrokeThis;
string GemType;

short() {
  string blah;
  blah = HIW+"Tolkor's Battle Axe"+NORM+" ["+GemType+"]";
  if(MobWield) blah = HIW+"Tolkor's Battle Axe"+NORM+" (wielded) ["+GemType+"]";
  if(BrokeThis) blah = HIW+"Tolkor's Battle Axe"+NORM+" [BROKEN] ["+GemType+"]";
  return blah;  
}

set_mobwield(int num) { MobWield = num; }

set_brokethis(int num) { BrokeThis = num; }

set_gemtype(int num) {
  switch(num) {
    case 0 : GemType = "major gem of performance"; break;
    case 1 : GemType = "gem of inescapable horror"; break; 
    case 2 : GemType = "minds eye gem"; break;
    case 3 : GemType = "gem of battle rites"; break;
    case 4 : GemType = "major gem of agility"; break;
    case 5 : GemType = "major gem of vigor"; break;
    case 6 : GemType = "major gem of might"; break;
    case 7 : GemType = "major gem of accuracy"; break;
    case 8 : GemType = "major gem of wisdom"; break;
    case 9 : GemType = "major gem of faith"; break;    
    default : GemType = "major gem of performance"; break; 
  }
}