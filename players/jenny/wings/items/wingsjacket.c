#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   if(arg) return;
   set_name("red wings jacket");
   set_alias("jacket");
   set_id("wings jacket");
   set_ac(2);
   set_value(150);
   set_weight(2);
   set_type("armor");
   set_short("Detroit "+RED+"Red Wings "+NORM+"jacket");
   set_long(
      "This is a red nylon windbreaker.  It has a winged wheel logo\n"+
      "on the front, and the words "+RED+"Red Wings "+NORM+"written on the back.\n");
}
