#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_short(HIW+"Bottomless Beaker"+NORM);
  set_long("This is a magical apparatus, that thanks to an extremely powerful\n"+
           "enchantment may never be filled.\n");
  set_value(5);
  set_weight(1);
  set_id("beaker");
  set_alias("apparatus");
}
