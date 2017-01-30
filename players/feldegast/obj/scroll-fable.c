#include "defs.h"

inherit "/players/feldegast/std/book.c";

void reset(int arg)
{
  if(arg) return;
  set_id("scroll");
  set_alias("fable");
  set_short("An ancient scroll");
  set_long(
"This is an ancient scroll, frail and brittle containing knowledge\n"+
"and wisdom passed down from generation to generation.\n");
  set_weight(1);
  set_value(100);
  set_file(OBJ_PATH+"text/fable"+(random(3)+1)+".txt");
}
