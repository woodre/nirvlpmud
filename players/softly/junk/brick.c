#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("brick");
   set_short(HIY+"A gold brick"+NORM);
   set_alias("gold");
   set_long("An oddly shaped brick of solid gold.\n");
   set_weight(2);
   set_value(500);
   save_flag=0;
}
