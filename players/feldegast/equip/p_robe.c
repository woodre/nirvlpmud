#include "/players/feldegast/defines.h"

inherit "obj/armor.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg)return;
  set_name("robe");
  set_alias("purple robe");
  set_short(MAG+"A purple robe"+NORM);
  set_long("A purple robe with golden patterns stitched into it.\n");
  set_ac(1);
  set_type("misc");
  set_weight(1);
  set_value(500);
}
