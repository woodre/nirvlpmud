#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("salt");
  set_alias("grain");
  set_short("grain of salt");
set_long(
"This is a grain of salt from Mr. Salt.\n");
  set_value(150);
  set_weight(1);
}
