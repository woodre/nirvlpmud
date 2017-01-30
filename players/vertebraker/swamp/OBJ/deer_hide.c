#include "../define.h"
inherit ITEM;
reset(arg) {
   if(arg) return;
   set_id("hide");
   set_alias("deer hide");
   set_short("A deer hide");
   set_long(
      "This is the wide, cozy hide of a deer.  It has bloodstains\n"+
      "all over it, and needs to be cleaned.  But it could still be\n"+
      "sold for an excellent profit.\n");
   set_weight(1);
   set_value(900+random(100));
}
