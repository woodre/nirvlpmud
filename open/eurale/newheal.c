#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("N");
add_alias("A");
add_alias("A2");
set_short("S");
set_long(
  "Description of heal.\n");

add_cmd("cd");
set_type("many");
set_type_single("one");
set_msg(
  "What you see when you use it.\n");
set_msg2(
 " what others see when you use it.\n");
set_heal(hp,sp);
set_charges(number);
  set_msg_precharges("");
  set_msg_postcharges("");
set_intox(amt);  /*  intox  soak  stuff  */
set_value(per);
set_msg_intoxed(
  "Msg you get when you're too intoxed.\n");  /*  intoxed  soaked stuffed  */
set_empty_msg(
  "After last charge is used.\n");
}
