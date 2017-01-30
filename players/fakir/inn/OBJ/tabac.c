#include "/players/fakir/color.h"
#define tp this_player()->query_name()
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("tabac");
   set_short("A small bag of tabac");
   set_long(
   "A small cloth bag with a drawstring top containing about an ounce\n"+
   "of tabac, the preferred smoking substance in the Two Rivers area. \n");
   set_weight(1);
   set_value(25);
}