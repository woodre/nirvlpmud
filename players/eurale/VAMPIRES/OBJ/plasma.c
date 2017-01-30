/*  Updated to new heal format 7/28/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("plasma");
set_short("bottle of "+HIR+"plasma"+NORM);
set_long(
  "This is plasma from the blood that has been donated by dying individuals.\n"+
  "It has been pasturized into it's current potent form and may be 'swallow'ed.\n");

add_cmd("swallow");
set_type("swallows");
set_type_single("swallow");
set_msg(HIR+"You swallow a mouthful of the thick plasma.\n"+NORM);
set_heal(45,45);
set_charges(3);
  set_msg_precharges(HIR+"^"+NORM);
  set_msg_postcharges(HIR+"^"+NORM);
set_intox(14);
set_value(300);
set_msg_intoxed(
  HIR+"You RETCH back into the bottle and FEEL SICK.\n"+NORM);
set_empty_msg(
  HIR+"You SMASH the empty plasma vial on the ground.\n"+NORM);
}
