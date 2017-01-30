#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   if(arg) return;
   set_name("swatch watch");
   set_alias("swatch");
   set_id("watch");
   set_ac(1);
   set_value(150);
   set_weight(1);
   set_type("misc");
   set_short(WHT+"A"+HIC+" swatch "+HIM+"watch"+NORM);
   set_long(
      "This is a very colorful watch, with rubber band type things across\n"+
      "the face.  These were very stylish in the late 80's.  You couldn't be\n"+
      "a popular kid without one.\n"+
      "It is "+HIC+ctime()+NORM+"\n");
}
