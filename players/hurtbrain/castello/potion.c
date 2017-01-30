/*  Changed to new heals format 8/18/02 - Eurale  */
/* Cost 15hpts @ intox 0 * 60/pt = 900  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("potion");
add_alias("roman potion");
set_short("A Roman potion");
set_long(
  "This is a healing potion that you may 'quaff' to use.\n");

add_cmd("quaff");
set_type_single("quaff");
set_msg("");
set_msg2(
  " quaffs a Roman potion.\n");
set_heal(15,15);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(0);  /*  intox  soak  stuff  */
set_value(450);
set_msg_intoxed(
  "\n");
set_empty_msg(
  "You quaff the potion and belch in satisfaction.\n");
}
