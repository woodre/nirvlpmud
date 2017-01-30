#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   if(arg) return;
   set_name("michael jackson's glove");
   set_alias("gloves");
   set_id("glove");
   set_ac(1);
   set_value(150);
   set_weight(1);
   set_type("gloves");
   set_short(BOLD+WHT+"Michael Jackson's Glove"+NORM);
   set_long(
      "This is not a pair of gloves, just one glove.  It is silvery white\n"+
      "with lots of rhinestones.  Michael Jackson often wore this glove in\n"+
      "his music videos.\n");
}
