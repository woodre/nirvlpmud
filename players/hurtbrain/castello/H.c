/*  Changed to new heals format 8/15/02 - Eurale  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("bubbles");
add_alias("7up");
set_short(HIC+"bubbles of 7up"+NORM);
set_long(
  "Carbonated bubbles of delicious 7up.\n");

add_cmd("drink");
set_type_single("bubbles");
set_msg("");
set_msg2(
  " drinks the carbonated 7up bubbles.\n");
set_heal(30,30);
set_charges(1);
  set_msg_precharges(HIC+"{"+NORM);
  set_msg_postcharges(HIC+"}"+NORM);
set_intox(10);  /*  intox  soak  stuff  */
set_value(100);
set_msg_intoxed(
  "You feel too full for any more 7up.\n");
set_empty_msg(
  HIC+"You enjoy the delicious flavor of the carbonated 7up bubbles.\n"+NORM);
}
