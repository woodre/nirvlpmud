/*  Changed to new heals format 8/21/02 - Eurale  */
/*  Cost 50 *hpts @ intox 14 * 10/pt = 500 * 3 drinks = 1500  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("pepsi");
add_alias("bottle");
set_short("2 litre bottle of Pepsi");
set_long(
  "A 2 litre bottle of Pepsi.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  "You drink a HUGE mouthful of the ice cold Pepsi.\n");
set_msg2(
  " takes a drink from the bottle of Pepsi.\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_soak(14);  /*  intox  soak  stuff  */
set_value(750);
set_msg_soaked(
  "You are entirely too full to drink any more.\n");
set_empty_msg(
  "You chug down the Pepsi and belch loudly.\n");
}
