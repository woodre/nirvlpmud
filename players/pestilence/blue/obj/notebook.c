#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("notepad");
  set_alias("notepad");
  set_short("a notepad");
set_long(
"This is a small notepad, red in color, with the rings on the top.\n"+
"Steve used this notepad to write clues in.  It seems useless to you.\n");
  set_value(300);
  set_weight(1);
}
