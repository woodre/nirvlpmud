#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
  if(arg) return;
  set_id("big-uns");
set_alias("magazine");

set_short(""+BLU+"A copy of BIG-UNS"+NORM+"");

set_long("This is Al Bundy's favorite girly magazine.  He has a whole collection of these in his basement. \n");

set_weight(1);
set_light(-1);
set_value(500);
}
