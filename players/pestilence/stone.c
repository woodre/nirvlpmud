inherit "obj/treasure";
#include "/players/pestilence/ansi.h"

reset(arg) {
  if(arg) return;
  set_id("stone");
  set_alias("mystical stone");
  set_short(""+HIK+"A "+HIW+"Mystical"+HIK+" stone"+NORM+"");
  set_long(
"This is a "+HIW+"mystical"+HIK+" stone"+NORM+" that can restore a guild object to a member\n"+
"of the Dark Order, if they happen to lose it.  The command\n"+
"is guild_restore.\n"
  );
  set_value(0);
}
get() { return 0; }
