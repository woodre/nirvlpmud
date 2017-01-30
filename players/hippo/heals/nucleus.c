/*  Changed to new heals format 8/15/02 - Eurale  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("nucleus");
add_alias("cell");
set_short(MAG+"nucleus of a cell"+NORM);
set_long(
  "The edible nucleus of a cell.\n");

add_cmd("eat");
set_type_single("nucleus");
set_msg("");
set_msg2(
  " eats the cell nucleus.\n");
set_heal(20,20);
set_charges(1);
  set_msg_precharges(MAG+"{"+NORM);
  set_msg_postcharges(MAG+"}"+NORM);
set_intox(6);  /*  intox  soak  stuff  */
set_value(100 + random(100));
set_msg_intoxed(
  "You cannot eat another bite at the moment.\n");
set_empty_msg(
  MAG+"You masticate and swallow the cell nucleus.\n"+NORM);
}
