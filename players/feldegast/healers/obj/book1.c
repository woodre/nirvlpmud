#include "../def.h"

inherit "/players/feldegast/std/book.c";

void reset(int arg)
{
  if(arg) return;
  set_id("tome");
  set_alias("book");
  set_short("A leather-bound tome");
  set_long(
"This is a book entitled, \"The Book of Nevilyn\", an autobiography\n"+
"of the Healer and adventurer Nevilyn of the Frosty Peaks.\n");
  set_weight(1);
  set_value(100);
  set_file("/players/feldegast/healers/obj/book1.txt");
}
