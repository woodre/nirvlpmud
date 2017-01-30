#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("dust");
   set_alias("fairy dust");
   set_short(HIY+"Fairy Dust"+NORM);
   set_long(HIY+"A pile of sparkling fairy dust.\n"+NORM);
   set_value(350);
}

