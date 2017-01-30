#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){

   set_id("fittings");
   set_alias("brass");
   set_short("Brass fittings");
   set_long("Brass fittings that once adorned a naval vessel.\n");
   set_weight(1);
   set_value(400);
}

