#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
  if(arg) return;
  set_id("enostracker");
set_short();
set_long();
set_value(0);
set_dest_flag(1);
}
get() {return 0;}
