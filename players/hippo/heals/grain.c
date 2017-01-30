/*  Changed to new heals format 8/15/02 - Eurale  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("grain");
add_alias("crumbs");
set_short(YEL+"crumbs of grain"+NORM);
set_long(
  "What is left of some delicious crumbs of grain.\n");

add_cmd("eat");
set_type_single("crumbs");
set_msg("");
set_msg2(
  " eats the crumbs of grain.\n");
set_heal(20,20);
set_charges(1);
  set_msg_precharges(YEL+"{"+NORM);
  set_msg_postcharges(YEL+"}"+NORM);
set_stuff(10);  /*  intox  soak  stuff  */
set_value(150);
set_msg_stuffed(
  "You feel too full for any more.\n");
set_empty_msg(
  YEL+"You chew up and swallow the delicious crumbs of grain.\n"+NORM);
}
