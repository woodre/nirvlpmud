/*  Changed to new heals format 8/18/02 - Eurale  */
/*  Cost 50hpts @ intox 0 * 60/pt = 3000  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("dust");
add_alias("star dust");
add_alias("bag");
set_short("a bag of "+YEL+"star dust"+NORM);
set_long(
  "A small bag of magical star dust.  All one need to do is\n"+
  "throw the dust for healing.\n");

add_cmd("throw");
set_type_single("throw");
set_msg("");
set_msg2(
  " throws some star dust.\n");
set_heal(50,50);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(0);  /*  intox  soak  stuff  */
set_value(1500);
set_msg_intoxed(
  "\n");
set_empty_msg(
  YEL+"You throw some star dust into the air and feel better immediately.\n"+NORM);
}
