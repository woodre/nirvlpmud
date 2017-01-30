#include "/players/fakir/color.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("horn");
   set_short("A Curved Horn");
   set_long(
   "   This is the curved horn of a ram. It has been fitted with a\n"+
   "brass mouth piece and is used to signal the trolloc fist when\n"+
   "on the march.  It is the prized possession of all trolloc scouts.\n");
   set_weight(1);
   set_value(600);
}

