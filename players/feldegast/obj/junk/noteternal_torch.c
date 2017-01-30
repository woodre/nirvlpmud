#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_id("torch");
  set_short(BOLD+BLK+"Not-So-Eternal Torch"+NORM);
  set_long("This was an early prototype of the infamous Eternal Torch.\n");
  set_value(5);
  set_weight(1);
}
void init()
{
  add_action("cmd_light","light");
}
int cmd_light(string str)
{
  notify_fail("Light what?\n");
  if(!str || !id(str)) return 0;
  write("It looks like somebody used it too.\n");
  return 1;
}
