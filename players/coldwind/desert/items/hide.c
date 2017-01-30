#include "/players/coldwind/define.h"

inherit "obj/treasure";


reset(arg)  {
  if(arg) return;
   set_id("hide");
   set_alias("Proof of Fares's Life");
   set_short(""+HIW+"A stained hide"+NORM+"");   
   set_long(
   "A small hide that Fares was seen often wrapping around his\n"+
   "right arm before going into the battlefield. It seems in \n"+
   "good condition, despite the bloodstains on it.\n");
   
   set_weight(1);
   set_value(200);
}
query_save_flag(){ return 1; }
