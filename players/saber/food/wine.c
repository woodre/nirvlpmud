/* Changed to new heals format 8/15/02 - Eurale */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("wine");
add_alias("bottle");
add_alias("red wine");
set_short("bottle of "+HIR+"red wine"+NORM);
set_long(
  "A slender bottle of deep red wine.\n");

add_cmd("sip");
set_type_single("sip");
set_msg(
  "You take a sip from the bottle of "+HIR+"red wine.\n"+NORM);
set_msg2(
  " takes a sip from the bottle of "+HIR+"red wine.\n"+NORM);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(21);  /*  intox  soak  stuff  */
set_value(150);
set_msg_intoxed(
  "You are too inebriated to drink any more.\n");
set_empty_msg(
  "You finish off the bottle of "+HIR+"red wine.\n"+NORM);
}
