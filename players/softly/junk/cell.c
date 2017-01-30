#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("brain cell");
   set_short(HIR+"Brain Cell"+NORM);
   set_alias("cell");
   set_long("A brain cell, for those in need of one.\n");
   set_weight(0);
   set_value(0);
}
