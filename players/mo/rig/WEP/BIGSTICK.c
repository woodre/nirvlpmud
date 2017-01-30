inherit "/obj/weapon.c";

#include <ansi.h>

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   set_name("wrench");
   set_short(BOLD+"A crescent wrench"+NORM);
   set_long(
      "This is a large crescent wrench used to tighten pipes on\n"+
      "the oil wells on the Chinle Oil Platform.\n");
   set_type("club");
   set_class(100000000);
   set_weight(3);
   set_value(550+random(100));
}

