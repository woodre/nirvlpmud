#include "../define.h"
inherit ITEM;

reset(arg) {
   if(arg) return;
   set_short(GRN+"acidic slime"+NORM);
   set_long(
      "  A bubbling ooze that you gives off faint traces of\n"+
      "formaldehyde and bleach.  You think if you touch this,\n"+
      "you might not live much longer.....\n");
   set_id("slime");
   set_alias("acidic slime");
}

get() {
   write("You plunge into the slime, burning the skin away to the bone!\n");
   if(TP)
   TP->hit_player(140 + random(40), "other|poison");
   return 0; }
