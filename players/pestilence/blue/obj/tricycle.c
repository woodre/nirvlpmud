#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("tricycle");
  set_alias("tricycle");
  set_short("tricycle");
set_long(
"This is a small red tricycle.  It seems to be much to small for you to ride.\n");
  set_value(250);
  set_weight(2);
}
