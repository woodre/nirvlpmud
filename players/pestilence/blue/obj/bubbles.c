#include "/players/pestilence/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("bubbles");
  set_alias("soap bubbles");
  set_short("soap bubbles");
set_long(
"These are soap bubbles from Slippery Soap.\n");
  set_value(20 + random(200));
  set_weight(1);
}
