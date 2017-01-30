#include "../define.h"
inherit ITEM;
reset(arg) {
   if(arg) return;
   set_id("skin");
   set_short(HIY+"sn"+NORM+GRN+"ak"+HIY+"esk"+NORM+GRN+"in"+NORM);
   set_alias("snakeskin");
   set_long(
      "This is a green and yellow patterned snakeskin.\n"+
      "It probably would fetch a nice price at a shop.\n");
   set_value(150); }
