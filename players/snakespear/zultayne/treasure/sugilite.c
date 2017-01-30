#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("sugilite");
set_short("a chunk of "+HIM+"sugilite"+NORM);
set_long(
  "  A small chunk of sugilite.  A purplish stone of good, solid\n"+
  "weight.  It looks expensive and very dense.  Maybe you too\n"+
  "could get a fair price for this valueable stone.\n");
set_alias("qpiece8");
set_weight(3);
set_value(300);
}
