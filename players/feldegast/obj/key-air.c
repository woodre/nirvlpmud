#include "/players/feldegast/defines.h"

#define WEIGHT 1

inherit "obj/treasure";

void reset(int arg)
{
  if(arg) return;
  set_id("key");
  set_alias("air key");
  set_short(CYN+"Air key"+NORM);
  set_long(
"The air key is not in fact a key, but rather a cubic shaped\n"+
"stone with a slot in the bottom.\n");
  set_weight(WEIGHT);
  set_value(1000);
}
query_element() { return "air"; }
