#include "/players/feldegast/defines.h"

inherit "/obj/armor.c";

void reset(int arg)
{
  if(arg) return;
  set_name("plate");
  set_alias("breastplate");
  set_short(BOLD+BLK+"Myrmidar Breastplate"+NORM);
  set_long(
"This is a breastplate formed by the tough chitinous shell of\n"+
"a Myrmidar.\n");
  set_ac(3);
  set_weight(5);
  set_value(750);
  set_type("armor"); /* 9-18-01 Doh! */
}
