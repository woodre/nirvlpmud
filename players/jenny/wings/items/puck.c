#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("jennypuck");
   set_alias("puck");
   set_short("puck");
   set_long(
      "This is a hockey puck.  It is a small, hard, black, disk shaped piece of rubber.\n"+
      "It is pretty heavy, and would hurt to be hit with.\n");
   set_weight(1);
   set_value(30);
}
