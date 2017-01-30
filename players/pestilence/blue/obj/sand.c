#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("sand");
  set_alias("sand");
  set_short("sand");
set_long(
"This is sand from Blue's sandbox, it is small and tan in color.\n");
  set_value(150);
  set_weight(1);
}
