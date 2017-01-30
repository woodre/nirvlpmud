#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("paper");
  set_alias("piece of paper");
  set_short("A piece of paper");
set_long(
"This is a piece of white paper with writing on it.  It appears to be Pig's homework\n");
  set_value(150 + random (100));
  set_weight(1);
}
