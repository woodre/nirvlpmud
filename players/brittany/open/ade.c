/*  Changed to new heal format 8/21/02 - Eurale  */
/*  Cost:  50hps at soak 12 * 12/pt = 600 * 3 drinks = 1800  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("lemonade");
add_alias("refreshing lemonade");
add_alias("bottle");
set_short("bottle of refreshing "+YEL+"lemonade"+NORM);
set_long(
  "A tall bottle of refreshing lemonade made from fresh-squeezed lemons.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  "You drink from the bottle of refreshing "+YEL+"lemonade.\n"+NORM);
set_msg2(
  " takes a drink of lemonade.\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_soak(12);  /*  intox  soak  stuff  */
set_value(500);
set_msg_soaked(
  "You feel too full to drink any more lemonade.\n");
set_empty_msg(
  "You finish off the last of the refreshing "+YEL+"lemonade.\n"+NORM);
}
