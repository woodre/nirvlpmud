#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("ring");
set_short("A "+HIR+"Ruby"+NORM+" Engagement Ring");
set_long(
  "  A silver banded ring with a large rudy inset on a six point setting.  The ruby\n"+
  "shines with an inner beauty, much like the owner of the ring.  This ring is only\n"+
   "a small token of a lust more powerful than chocolate.\n");
set_weight(0);
set_value(0);
}
drop ()  { return 1; }
get() { return 1; }
