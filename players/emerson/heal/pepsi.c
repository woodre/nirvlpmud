/*  Changed to new heals format 8/21/02 - Eurale  */
/*  Cost 10 *hpts @ intox 14 * 10/pt = 100  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("pepsi");
add_alias("can");
add_alias("diet pepsi");
set_short("can of Diet Pepsi");
set_long(
  "A 12 oz can of bubbly Diet Pepsi.\n");

add_cmd("drink");
set_type_single("drink");
set_msg("");
set_msg2(
  " drinks a can of Diet Pepsi.\n");
set_heal(10,10);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_soak(14);  /*  intox  soak  stuff  */
set_value(75);
set_msg_soaked(
  "You are entirely too full to drink any more.\n");
set_empty_msg(
  "You chug down the Pepsi and belch loudly.\n");
}
