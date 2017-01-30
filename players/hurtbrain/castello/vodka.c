/* Changed to new heal format 8/19/02 - Eurale  */
/*  Cost:  50hpts @ intox 9 * 15/pt = 750  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("vodka");
add_alias("shot");
set_short(BOLD+"shot of vodka"+NORM);
set_long(
  "A small shot of vodka you can drink.\n");

add_cmd("drink");
set_type_single("drink");
set_msg("");
set_msg2(
  " drinks a shot of vodka.\n");
set_heal(50,50);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(9);  /*  intox  soak  stuff  */
set_value(375);
set_msg_intoxed(
  "You feel too intoxicated for more vodka at the moment.\n");
set_empty_msg(
  BOLD+"You drink down the shot of vodka and grimace.\n"+NORM);
}
