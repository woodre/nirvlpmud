#include "../define.h"
inherit ITEM;
reset(arg) {
   if(arg) return;
   set_id("leg");
   set_short("a stork's leg");
   set_alias("stork leg");
   set_long(
      "This is the long, sinewy flesh of a stork.  It can\n"+
      "often be sold at stores for a nice earning.\n");
   set_weight(1);
   set_value(500+random(200));
}
