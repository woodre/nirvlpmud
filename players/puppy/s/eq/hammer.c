#include "/players/puppy/define.h"
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("hammer");
   set_type("club");
   set_short("A hammer");
   set_long(
      "A small hammer used to pound things.  The handle on it\n"+
      "has seen better days but it still has a good many years\n"+
      "left in it.\n");
   set_class(4);
   set_weight(1);
   set_value(100);
}
