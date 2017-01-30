#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("pepper");
  set_alias("grain");
  set_short("grain of pepper");
set_long(
"This is a grain of pepper from Mrs. Pepper.\n");
  set_value(150);
  set_weight(1);
}
