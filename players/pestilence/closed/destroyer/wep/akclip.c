inherit "obj/treasure";
#include "/players/pestilence/ansi.h"

reset(arg) {
  if(arg) return;
  set_id("ak_clip");
  set_alias("ak 47 clip");
  set_short(""+HIK+"AK "+HIW+"47"+HIK+" clip"+NORM+"");
  set_long(
"This is a "+HIW+"mystical"+HIK+" stone"+NORM+" that can restore a guild object to a member\n"+
"of the Dark Order or the Army, if they happen to lose it.  The command\n"+
 "is guild_restore and army_restore, respectively.\n"
  );
  set_value(0);
}

