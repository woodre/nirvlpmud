#include "/open/ansi.h"
inherit "/obj/treasure";
get() { return 0; }

reset(arg) {
   if(arg) return;
   set_light(2);
   set_id("fire");
   set_alias("campfire");
   set_short("A "+HIR+"blazing"+NORM+" campfire");
   set_long(
      "A fiery campfire that was started by a swamp guard to keep\n"+
      "warm.  It is emitting black tufts of smoke into the air like\n"+
      "a beacon.\n"); }
