/* Changed to new heal format 8/19/02 - Eurale  */
/*  Cost:  40hpts @ intox 9 * 15/pt = 600  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("rum");
add_alias("mug");
set_short("mug of rum");
set_long(
  "A small mug of rum you can drink.\n");

add_cmd("drink");
set_type_single("drink");
set_msg("");
set_msg2(
 " drinks a mug of rum.\n");
set_heal(40,40);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(9);  /*  intox  soak  stuff  */
set_value(300);
set_msg_intoxed(
  "You feel too intoxicated for more rum at the moment.\n");
set_empty_msg(
  "You tip back the mug and finish off the delicious rum.\n");
}
