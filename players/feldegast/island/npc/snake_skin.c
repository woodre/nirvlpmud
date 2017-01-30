#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("material for maria");
  set_alias("snakeskin");
  set_short("a snakeskin");
  set_long(
"This is the skin of a large snake.  You think a skilled\n"+
"craftsperson could make something useful out of it.\n"
  );
  set_value(200);
  set_weight(1);
}

