/* Changed to new heal format 8/21/02 - Eurale  */
/*  Cost:  20hpts @ stuff 9 * 15/pt = 300  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("pizza");
add_alias("slice");
add_alias("hot pizza");
set_short("slice of hot pizza");
set_long(
  "A large slice of deep dish pizza with double cheese.\n");

add_cmd("eat");
set_type_single("slice");
set_msg(
  "\n");
set_msg2(
  " eats a slice of hot pizza.\n");
set_heal(20,20);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_stuff(9);  /*  intox  soak  stuff  */
set_value(150);
set_msg_stuffed(
  "You feel too bloated to eat any more.\n");
set_empty_msg(
  "You pop the last of the pizza into your mouth and swallow it.\n");
}
