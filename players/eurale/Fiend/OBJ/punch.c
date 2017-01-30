/*  Changed to new heal format 7/29/02 - Eurale  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("punch");
add_alias("planters punch");
add_alias("mug");
set_short(HIY+"mug of planters punch"+NORM);
set_long(
  "A delicious blend of fruit juices and potent rum with an after-taste of\n"+
  "of roasted coconut.  Label reads:  Bottled for Fiendsville Pub\n");

add_cmd("drink");
set_type("drinks");
set_type_single("drink");
set_msg(
  HIY+"You lick your lips and drink deeply of the planters punch.\n"+NORM);
set_msg2(
  " drinks deeply of the planters punch.\n");
set_heal(50,50);
set_charges(3);
  set_msg_precharges("");
  set_msg_postcharges("");
set_intox(10);  /*  intox  soak  stuff  */
set_value(500);
set_msg_intoxed(
  "You try to drink another swallow of punch but fail.\n");
set_empty_msg(
  HIY+"You finish off the punch and bury the mug.\n"+NORM);
}
