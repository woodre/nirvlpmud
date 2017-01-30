#include <ansi.h>

query_message_hit(int tmp) {
  string *mess;
  switch(tmp) {
    case 1..5:
      mess = ({" with a poorly executed attack",BOLD+"slightly"+NORM+" injured"});
    break;
    case 6..8:
      mess = ({" with a weak series of blows",BOLD+"moderately"+NORM+" harmed"});
    break;
    case 9..12:
      mess = ({" with a flashy attack combibation",BOLD+"confounded"+NORM});
    break;
    case 13..16:
      mess = ({" with multiple, stinging strikes",RED+"BRUTALIZED"+NORM});
    break;
    case 17..20:
      mess = ({" with a nearly perfected combo",HIY+"DOMINATED"+NORM});
    break;
    case 21..24:
      mess = ({", landing multiple "+BOLD+"deadly"+NORM+" blows" ,HIR+"savagely"+NORM+ "thrashed"});
    break;
    case 25..28:
      mess = ({", striking with "+BOLD+"impossible speed"+NORM,HIR+HBYEL+"O W N E D"+NORM});
    break;
    case 29..30:
      mess = ({", attacking with "+HIR+"GODLIKE"+NORM+" perfection",HIM+"OBLITERATED"+NORM});
    break;
    default:
      mess = ({" into a squirming, "+HIR+"bloody"+NORM+" mess","completely "+HIC+"ANNIHILATED"+NORM});
  }
  return mess;
}