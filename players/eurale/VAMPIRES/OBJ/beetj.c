/* Updated to new heal format 7/28/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("juice");
add_alias("beet juice");
add_alias("vial");
set_short("vial of "+HIR+"beet juice"+NORM);
set_long(
  "A small vial of beet juice that you can drink.\n");

set_type("drinks");
set_type_single("drink");
set_msg(
  HIR+"You tip your head back and drink some beet juice.\n"+NORM);
add_cmd("drink");
set_heal(45,45);
set_charges(3);
  set_msg_precharges(HIR+"^"+NORM);
  set_msg_postcharges(HIR+"^"+NORM);
set_soak(14);
set_value(350);
set_msg_soaked(
  "You GAG as you try to take another drink of "+HIR+"beet juice"+NORM);
set_empty_msg(
  HIR+"You finish the beet juice and SMASH the vial.\n"+NORM);
}
