/* Changed over to new heal format 8/15/02 - Eurale  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("wine");
add_alias("bottle");
add_alias("white wine");
set_short("bottle of "+HIW+"white wine"+NORM);
set_long(
  "A large bottle of sparkling white wine.\n");

add_cmd("sip");
set_type("sips");
set_type_single("sip");
set_msg(
  "You take a sip from the bottle of "+HIW+"white wine.\n"+NORM);
set_msg2(
  " takes a sip from the bottle of "+HIW+"white wine.\n"+NORM);
set_heal(25,25);
set_charges(7);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(14);  /*  intox  soak  stuff  */
set_value(100);
set_msg_intoxed(
  "You are too inebriated to drink any more.\n");
set_empty_msg(
  "You finish off the bottle of "+HIW+"white wine.\n"+NORM);
}
