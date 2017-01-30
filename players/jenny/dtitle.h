/* patched by verte 4-11-01 to allow for new xlv system */
#include "/players/snow/dervish/def.h"

dtitle() {
  int lev;
  string str;
  lev = TP->query_level();
  if(lev > 19) { write("Set your own title.\n"); return 1; }
  lev += TP->query_extra_level();
  switch(lev) {
    case 1..5  : str = "the Slave to the Sands"; break;
    case 6..7  : str = "the Servant of the Sands"; break;
    case 8..9  : str = "the Initiate of the Sands"; break;
    case 10..11: str = "the Acolyte of the Sands"; break;
    case 12..13: str = "the "+BOLD+"Apprentice Mystic"+OFF; break;
    case 14..15: str = "the "+BOLD+"Mystic of the Sands"+OFF; break;
    case 16..17: str = "the "+BOLD+"Holder "+OFF+"of "+CYAN+"Madness"+OFF;
    break;
    case 18    : str = "the "+RED+"Mystic "+OFF+"of "+BOLD+RED+"Chaos"+OFF;
    break;
    case 19..23: str = "the "+RED+"Whirling "+BOLD+"Master"+OFF; break;
    case 24..28: str = "the "+BOLD+CYAN+"Master "+OFF+"of
"+BOLD+RED+"Winds"+OFF;
                 break;
    case 29..33: str = "the "+BOLD+MAGENTA+"Master "+OFF+"of "+BOLD+RED+
                       "Particles"+OFF; break;
    case 34..39: str = "the "+BOLD+RED+"Soul "+OFF+"of the "+MAGENTA+
                       "Raging "+OFF+BOLD+RED+"Storm"+OFF; break;
     case 40: str = "the "+BOLD+RED+"SandStorm Incarnate"+OFF; break;
     default: str = "the "+BOLD+RED+"SandStorm Incarnate"+OFF; break;
  }
  TP->set_title(str);
  write("Title set.\n"); return 1; }
