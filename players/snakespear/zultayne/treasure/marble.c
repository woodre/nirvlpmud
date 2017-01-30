#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("marble");
set_alias("qpiece6");
set_short("a morsel of "+HIW+"marble"+NORM);
set_long(
  "  This is a small morsel of marble.  It is a carbonate of lime\n"+
  "that might be used for protective spells.  It could be carried\n"+
  "for personal success.  It appears to be very expensive!\n");
set_weight(3);
set_value(300);
}
