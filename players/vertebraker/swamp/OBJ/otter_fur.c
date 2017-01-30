#include "../define.h"
inherit ARMOUR;
reset(arg) {
   if(arg) return;
   set_id("fur");
   set_alias("otter fur");
   set_short("An "+YEL+"otter fur"+NORM);
   set_weight(1);
   set_long(
      "This is the beautiful fur of an otter that provides\n"+
      "warmth and protection for those in need.  It looks\n"+
      "like it may also fetch a price at the shop.\n");
   set_ac(1);
   set_type("armor");
   set_value(450);
}
