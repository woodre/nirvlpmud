
#include "/players/feldegast/defines.h"

inherit "obj/armor.c";

void reset(int arg)
{
  set_name("shield");
  set_short(BOLD+BLK+"Myrmidar Shield"+NORM);
  set_long(
"This is a rounded buckler formed by a myrmidar plate and\n"+
"tough leather.\n");
  set_ac(1);
  set_weight(3);
  set_value(500);
  set_type("shield");
}
