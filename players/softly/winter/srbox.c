#include "/players/softly/misc/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("Skate Return");
   set_short("A box marked 'Skate Return'");
   set_alias("box");
   set_long("A sturdy wooden box is anchored here.\n\
Carved in the top are the words 'Return Skates'.\n");
   set_weight(50000);
   set_value(0);
}
