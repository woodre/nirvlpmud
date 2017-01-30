/* Changed to new heal format 8/19/02 - Eurale  */
/*  Cost:  45hpts @ stuff 9 * 15/pt = 675 * 3 slices = 2025  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("pizza");
add_alias("slice");
set_short("large stuffed-crust pizza");
set_long(
  "A large stuffed-crust pizza designed to be eaten backwards... crust first.\n");

add_cmd("eat");
set_type("slices");
set_type_single("slice");
set_msg(
  "You gobble down a slice of hot, tasty pizza.\n");
set_msg2(
  " eats a slice of hot pizza.\n");
set_heal(45,45);
set_charges(3);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_stuff(9);  /*  intox  soak  stuff  */
set_value(500);
set_msg_stuffed(
  "You feel too bloated to eat any more.\n");
set_empty_msg(
  "You scarf down the last slice of pizza and wipe your mouth.\n");
}
