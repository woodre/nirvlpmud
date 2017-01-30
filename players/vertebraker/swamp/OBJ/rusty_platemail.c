#include "../define.h"
inherit ARMOUR;

reset(arg) {
   if(arg) return;
   set_short("rusty platemail armor");
   set_long(
      "A beat-up suit of platemail armor that appears to\n"+
      "have been hidden within the grove for some time.\n");
   set_id("platemail");
   set_type("armor");
   set_alias("rusty platemail");
   set_weight(4);
   set_value(300+random(100));
   set_ac(-1);
}

wear(str) {
   if(id(str)) {
      write("That would be pointless...\n"+
         "The armor is way past its prime.\n");
      return 1; }
    ::wear(str);
}
