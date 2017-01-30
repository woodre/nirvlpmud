/* Changed to new heal format 8/19/02 - Eurale  */
/*  Cost:  30hpts @ intox 9 * 15/pt = 450  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("brandy");
add_alias("snifter");
set_short(MAG+"snifter of brandy"+NORM);
set_long(
  "A small snifter of brandy you can drink.\n");

add_cmd("drink");
set_type_single("drink");
set_msg("");
set_msg2(
  " downs a snifter of brandy.\n");
set_heal(30,30);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(9);  /*  intox  soak  stuff  */
set_value(225);
set_msg_intoxed(
  "You feel too intoxicated for more brandy at the moment.\n");
set_empty_msg(
  MAG+"You finish off the snifter of brandy and grin.\n"+NORM);
}
