/*  Changed to new heal format 8/21/02 - Eurale  */
/*  Cost:  50hps at stuff 12 * 12/pt = 600 * 3 bites = 1800  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("bowl of rice");
add_alias("bowl");
add_alias("rice");
set_short("A bowl of "+HIW+"steamed rice"+NORM);
set_long(
  "A bowl of steamed rice that you can eat for energy.\n");

add_cmd("eat");
set_type("bites");
set_type_single("bite");
set_msg(
  HIW+"You gobble down some steamed rice.\n"+NORM);
set_msg2(
  " takes a bite from a bowl of steamed rice.\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges("[");
  set_msg_postcharges("]");
set_stuff(12);  /*  intox  soak  stuff  */
set_value(500);
set_msg_stuffed(
  "You feel too full to eat any more rice.\n");
set_empty_msg(
  HIW+"You stuff the last tuft of rice into your mouth.\n"+NORM);
}
