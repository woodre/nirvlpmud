inherit "/obj/weapon.c";

#include <ansi.h>

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   set_name("putter");
   set_short("An Odyssey Putter");
   set_long(
      "One of the finest putters around.  It is pretty useless\n"+
      "as a weapon but it can put a ball in the hole.\n");
   set_type("polearm");
   set_class(5);
   set_weight(1);
   set_value(4000);
}

