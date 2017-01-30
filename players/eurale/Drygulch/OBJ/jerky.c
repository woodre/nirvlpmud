/* Changed to new heal format 8/21/02 - Eurale  */
/*  Cost:  35hpts @ stuff 14 * 10/pt = 350 * 3 bites = 1050  */
#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("jerky");
add_alias("strip");
add_alias("beef jerky");
set_short(RED+"strip of beef jerky"+NORM);
set_long(
  "A lean strip of dried beef jerky cut from the flank.\n");

add_cmd("eat");
set_type("bites");
set_type_single("bite");
set_msg(
  RED+"You chew off a bite of dried beef jerky.\n"+NORM);
set_msg2(
  " bites off a piece of dried beef jerky.\n");
set_heal(35,35);
set_charges(3);
  set_msg_precharges(RED+"<"+NORM);
  set_msg_postcharges(RED+">"+NORM);
set_stuff(14);  /*  intox  soak  stuff  */
set_value(300);
set_msg_intoxed(
  "You feel too full for any more beef jerky now.\n");
set_empty_msg(
  RED+"You chew up and swallow the last bite of beef jerky.\n"+NORM);
}
