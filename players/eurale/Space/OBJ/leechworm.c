/*  Changed to new heals format 7/29/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("leechworm");
add_alias("leech");
add_alias("worm");
set_short(HIY+"leech"+HIR+"worm"+NORM);
set_long(
  "A fat, juicy leechworm dug from the tundra of outer space.  With rings of\n"+
  "bright yellow and red, it is often eaten as a delicacy.\n");

add_cmd("eat");
set_type("bites");
set_type_single("bite");
set_msg(
  HIR+"You bite off and swallow "+HIY+"a piece of the leechworm.\n"+NORM);
set_msg2(
  " bites off and swallows a piece of leechworm.\n");
set_heal(40 + random(16),40 + random(16));
set_charges(2);
  set_msg_precharges("");
  set_msg_postcharges("");
set_stuff(10);  /*  intox  soak  stuff  */
set_soak(10);
set_value(250);
set_msg_stuffed(
  "You are too full and gag on the leechworm.\n");
set_msg_soaked(
  "You gag as you try to take another bite of leechworm.\n");
set_empty_msg(
  BOLD+"You shove the last disgusting piece of leechworm into your\n"+
  "mouth and swallow it.\n"+NORM);
}
