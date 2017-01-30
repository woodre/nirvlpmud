inherit "obj/treasure";
#include "/players/pestilence/ansi.h"

reset(arg) {
  if(arg) return;
  set_id("shell");
  set_alias("egg shell");
  set_short(""+HIW+"A piece of an egg shell"+NORM+"");
  set_long(
"This is a piece of an "+HIW+"egg shell"+NORM+" broken from the egg sack.\n"+
"There were a few baby ants within the egg before it was cracked and opened.\n"
  );
  set_weight(3);
  set_value(0);
}
get() { return 0; }
