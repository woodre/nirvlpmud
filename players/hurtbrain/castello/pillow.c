/*  Changed to new heals format 8/18/02 - Eurale  */
/*  Cost  Full heal = 10000  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("pill");
add_alias("white pill");
set_short(HIW+"octagonal white pill"+NORM);
set_long(
  "A large, octagonal white pill that you might be able to swallow.\n");

add_cmd("swallow");
set_type_single("swallow");
set_msg("");
set_msg2(
  " swallows a large white pill.\n");
set_heal(650,650);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(0);  /*  intox  soak  stuff  */
set_value(10000);
set_msg_intoxed(
  "\n");
set_empty_msg(
  "You swallow a "+HIW+"large octagonal white pill"+NORM+" and feel better.\n");
}
