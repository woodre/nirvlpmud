#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("crayon");
  set_alias("red crayon");
  set_short(""+HIR+"red"+NORM+" crayon");
set_long(
"This is a "+HIR+"red"+NORM+" crayon Steve uses to write in the notebook with.\n");
  set_value(50);
  set_weight(3);
}
