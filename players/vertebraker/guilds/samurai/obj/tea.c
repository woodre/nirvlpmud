/*  Changed to new heal format 8/21/02 - Eurale  */
/*  Cost:  50hps at soak 12 * 12/pt = 600 * 3 drinks = 1800  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("green tea");
add_alias("tea");
add_alias("bottle");
set_short("A bottle of "+GRN+"green tea"+NORM);
set_long(
  "A tall bottle of green tea.\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  "You drink from the bottle of refreshing "+GRN+"green tea.\n"+NORM);
set_msg2(
  " takes a drink of green tea.\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges("[");
  set_msg_postcharges("]");
set_soak(12);  /*  intox  soak  stuff  */
set_value(500);
set_msg_soaked(
  "You feel too full to drink any more green tea.\n");
set_empty_msg(
  "You finish off the last of the refreshing "+GRN+"green tea.\n"+NORM);
}
