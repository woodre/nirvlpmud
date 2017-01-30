#include "defs.h"

inherit "obj/armor";

string color;

random_color() {
  switch(random(7)) {
    case 0: return HIM+"purple"+NORM; break;
    case 1: return BLU+"midnight blue"+NORM; break;
    case 2: return HIG+"forest green"+NORM; break;
    case 3: return HIR+"fiery red"+NORM; break;
    case 4: return BLK+BOLD+"grey"+NORM; break;
    case 5: return YEL+"gold hued"+NORM; break;
    case 6: return HIB+"royal blue"+NORM; break;
    default: return "plain";
  }
}

reset(arg) {
  if(arg) return;
  color=random_color();
  set_name("cloak");
  set_alias("tournament item");
  set_short("A "+color+" cloak");
  set_long(
    "This is a heavy "+color+" cloak with an additional layer of supple\n"+
    "leather for extra protection.  It has a silver clasp bearing the\n"+
    "crossed swords and shield symbol of the tournament at the neck.\n"
  );
  set_ac(2);
  set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(2);
  set_value(0);
}

