/*  Heal calculated using new heal format 6/4/03 - Eurale */
/* 16 tox/80 heal = .2 = 16/pt(80) = 1280 for the heal  */

/* Approved by Pain, 6/5/03 */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("poppers");
add_alias("blood poppers");
add_alias("popper");
set_short(HIR+"blood poppers"+NORM);
set_long(HIR+
  "These slender glass tubes are filled with condensed blood that you can\n"+
  "drink and are called 'blood poppers' by the undead.\n"+NORM);

add_cmd("drink");
set_type("poppers");
set_type_single("popper");
set_msg(HIR+"You slam down one of the powerful blood poppers.\n"+NORM);
set_heal(40,40);
set_charges(2);
  set_msg_precharges(HIR+"^"+NORM);
  set_msg_postcharges(HIR+"^"+NORM);
set_intox(8);
set_value(450);
set_msg_intoxed(
  HIR+"You pull the popper back feeling too ill to drink it.\n"+NORM);
set_empty_msg(
  HIR+"You drink the last blood popper.\n"+NORM);
}
