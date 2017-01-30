/*  Changed to new heal format 8/21/02 - Eurale  */
/*  Cost:  50hps at soak 12 * 12/pt = 600 * 3 drinks = 1800  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("bottle of sake");
add_alias("sake");
add_alias("bottle");
set_short("A bottle of "+BOLD+"sake"+NORM);
set_long(
  "A bottle of sake that you can drink.\n");

add_cmd("drink");
set_type("swallows");
set_type_single("swallow");
set_msg(
  "You take a drink of "+BOLD+"sake.\n"+NORM);
set_msg2(
  " takes a drink of "+BOLD+"sake"+NORM+".\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges("[");
  set_msg_postcharges("]");
set_intox(12);  /*  intox  soak  stuff  */
set_value(500);
set_msg_intoxed(
  "You feel too drunk to drink any more sake.\n");
set_empty_msg(
  "You down the last of the "+BOLD+"sake.\n"+NORM);
}
