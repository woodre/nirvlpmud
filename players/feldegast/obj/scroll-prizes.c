#include "/players/feldegast/defines.h"
inherit "/players/feldegast/std/book.c";

void reset(int arg)
{
  if(arg) return;
  set_id("scroll");
  set_alias("prizelist");
  set_short("Scroll of Prizes");
  set_long(
"This is a somewhat dog-eared scroll written in neat, but hurried\n"+
"script.\n");
  set_weight(1);
  set_value(1);
  set_file(OBJ_PATH+"text/prizelist.txt");
}
