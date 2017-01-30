/*  Changed to new heals format 8/18/02 - Eurale  */
/*  Cost:  -11intox @ 20/pt = 200  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("potion");
add_alias("sobering potion");
set_short(HIR+"a sobering potion"+NORM);
set_long(
  "A small but powerful sobering potion.\n");

add_cmd("drink");
set_type_single("drink");
set_msg("You drink a potion and make an awful face.\n");
set_msg2(
  " drinks a potion and makes an awful face.\n");
set_heal(0,0);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(-11);  /*  intox  soak  stuff  */
set_value(100);
set_msg_intoxed(
  "\n");
set_empty_msg(
  HIR+"You gag down the sobering potion and feel less intoxicated.\n"+NORM);
}
