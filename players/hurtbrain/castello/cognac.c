/*  Changed to new heals format 8/18/02 - Eurale  */
/*  Cost:  20hpts @ intox 9 * 15/pt = 300  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("cognac");
add_alias("french cognac");
add_alias("amber cognac");
set_short("small bottle of "+YEL+"amber French cognac"+NORM);
set_long(
  "A small bottle of amber cognac you can drink.\n");

add_cmd("drink");
set_type_single("drink");
set_msg("");
set_msg2(
  " drinks a bottle of grape wine.\n");
set_heal(20,20);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(9);  /*  intox  soak  stuff  */
set_value(150);
set_msg_intoxed(
  "You feel too intoxicated for more cognac at the moment.\n");
set_empty_msg(
  YEL+"You finish off the bottle of amber cognac and grin.\n"+NORM);
}
