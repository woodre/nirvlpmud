#include "../define.h"
inherit ITEM;
reset(arg) {
   if(arg) return;
   set_id("beak");
   set_short("A duck's beak");
   set_long(
      "This is a bright yellow duck's beak.\n"+
      "It would probably fetch a small price at\n"+
      "the town shop.\n");
   set_value(150);
   set_weight(1);
}
