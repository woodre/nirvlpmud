#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("spatula");
   set_short("A wooden spatula");
   set_long(
      "A carved spatula used to help create tasty dishes.\n");
   set_weight(1);
   set_value(50);
}
