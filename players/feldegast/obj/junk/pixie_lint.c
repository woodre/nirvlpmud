#include "defs.h"
inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_id("lint");
  set_alias("pixie lint");
  set_short(HIY+"Pixie Lint"+NORM);
  set_long("It's not quite as useful as pixie dust, but it's easier to get pixies\n"+
           "to part with.  Another advantage is that it won't make you sneeze\n"+
           "in the middle of difficult incantations.\n");
  set_weight(1);
  set_value(5);
}
