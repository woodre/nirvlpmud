/*  Changed to new heals format 8/19/02 - Eurale  */
/*  Cost 20hpts @ intox 0 * 60/pt = 1200  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("paper");
add_alias("parchment paper");
set_short("a parchment paper");
set_long(
  "This is a Parchment of Healing that you can read.\n");

add_cmd("read");
set_type_single("read");
set_msg("");
set_msg2(
  " reads a parchment paper.\n");
set_heal(20,20);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(0);  /*  intox  soak  stuff  */
set_value(600);
set_msg_intoxed(
  "\n");
set_empty_msg(
  "As you finish reading the parchment falls apart.\n");
}
