#include "/players/feldegast/defines.h"

#define WEIGHT 2

inherit "obj/treasure";

void reset(int arg)
{
  if(arg) return;
  set_id("key");
  set_alias("water key");
  set_short(HIB+"Water key"+NORM);
  set_long(
"The water key is not in fact a key, but rather a cubic shaped\n"+
"stone with a slot in the bottom.\n");
  set_weight(WEIGHT);
  set_value(1000);
}
query_element() { return "water"; }
