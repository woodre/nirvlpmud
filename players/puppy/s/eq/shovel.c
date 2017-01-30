#include "/players/puppy/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("shovel");
   set_type("club");
   set_short("A shovel");
   set_long(
      "A spaded shovel that Farmer Smurf uses to tend to his fields.\n");
   set_class(4);
   set_weight(1);
   set_value(75);
}
