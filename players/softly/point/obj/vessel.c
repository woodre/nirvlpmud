#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("Wrecked Vessel");
   set_short("Wrecked Vessel");
   set_alias("vessel");
   set_long("The hull of a wrecked vessel lies half buried in\n\
the sand.  It looks like you could 'enter' it.\n");
   set_weight(50000);
   set_value(0);
}
