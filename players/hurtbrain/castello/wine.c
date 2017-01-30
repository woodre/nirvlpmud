/*  Changed to new heals format 8/18/02 - Eurale  */
/*  Cost:  10hpts @ intox 9 * 15/pt = 150  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("wine");
add_alias("grape wine");
set_short("small bottle of "+BLU+"grape wine"+NORM);
set_long(
  "A small bottle of grape wine you can drink.\n");

add_cmd("drink");
set_type_single("drink");
set_msg("");
set_msg2(
  " drinks a bottle of grape wine.\n");
set_heal(10,10);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(9);  /*  intox  soak  stuff  */
set_value(75);
set_msg_intoxed(
  "You feel too intoxicated for more wine at the moment.\n");
set_empty_msg(
  BLU+"You finish off the bottle of grape wine and grin.\n"+NORM);
}
