#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("brush");
   set_alias("paint brush");
   set_short("A paint brush");
   set_long(
      "A paint brush made of thick Smurf hair.\n");
   set_weight(1);
   set_value(50);
}
