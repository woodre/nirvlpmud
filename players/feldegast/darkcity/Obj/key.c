#include "../def.h"

inherit "/obj/treasure.c";

void reset(int arg)
{
 if(arg) return;
  set_id(KEY);
  set_alias("key");
  set_short(HIW+"A silver key"+NORM);
  set_long("A simple key made out of a strange silvery metal\n"+
          "that seems to glow eerily in the dark.\n");
  set_value(100);
  set_weight(1);
}
