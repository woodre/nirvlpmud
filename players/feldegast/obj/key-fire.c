#include "/players/feldegast/defines.h"

#define WEIGHT 3

inherit "obj/treasure";

void reset(int arg)
{
  if(arg) return;
  set_id("key");
  set_alias("fire key");
  set_short(HIR+"Fire key"+NORM);
  set_long(
"The fire key is not in fact a key, but rather a cubic shaped\n"+
"stone with a slot in the bottom.\n");
  set_weight(WEIGHT);
  set_value(1000);
}
query_element() { return "fire"; }
