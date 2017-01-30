#include "/players/jenny/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("jennypuck");
   set_alias("puck");
   set_short("puck");
   set_long(
      "This is a souvenir hockey puck.  It is a small, hard, black, disk shaped\n"+
     "piece of ruber with the winged wheel logo of the Detroit Red Wings\n"+
     "on it.  This puck is pretty heavy, and would hurt to get hit with.\n");
   set_weight(1);
   set_value(40);
}
