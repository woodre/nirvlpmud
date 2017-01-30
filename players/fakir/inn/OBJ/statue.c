#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("jade statue");
   set_alias("statue");
   set_short("A "+BOLD+GREEN+"Jade"+OFF+" Statue");
   set_long(
   "A small statue of a heathen diety.  It is a crime to deal in such items in\n"+
   "the realm of the Two Rivers.  Though no doubt very valuable, it would not\n"+
   "be wise to take or sell this.\n");
   set_weight(1);
   set_value(250+random(250));
   
}

get() { if(environment() && !environment()->is_player() &&
this_player()) this_player()->set_crime(1); return 1; }
