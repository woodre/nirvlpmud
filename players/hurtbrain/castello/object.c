/*  Changed to new heals format 8/18/02 - Eurale  */
/* Cost 15hpts @ intox 0 * 60/pt = 900  */

#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("object");
add_alias("glowing object");
set_short(RED+"a strange glowing object"+NORM);
set_long(
  "A strange glowing red object that you can polish for healing.\n");

add_cmd("polish");
set_type_single("polish");
set_msg("");
set_msg2(
  " polishes the strange glowing object.\n");
set_heal(40,40);
set_charges(1);
  set_msg_precharges("<");
  set_msg_postcharges(">");
set_intox(0);  /*  intox  soak  stuff  */
set_value(1200);
set_msg_intoxed(
  "\n");
set_empty_msg(
  RED+"The strange object GLOWS BRIGHTLY and then disappears.\n"+NORM);
}
