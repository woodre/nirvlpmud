#include "/open/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

/* General Object Descriptions */
set_name("Heal");
add_alias("Healname_alias");
add_alias("Healname_alias2");
set_short("Heal_short");
set_long("Long Description of heal.\n");

/* Heal Message Descriptions */
set_type_single("one");
set_type("many");
set_msg("What you see when you use it.\n");
set_msg2("What others see when you use it.\n");

/* Heal functionality */
set_value(per);
add_cmd("consume");
set_heal(hp,sp);
set_charges(number);
set_intox(amt);      /*  intox  soak  stuff  */

/* Optional Use */
/* set_msg_precharges("");   */
/* set_msg_postcharges("");  */
/* set_msg_stuffed("Msg you get when you're too stuffed.\n"); */
/* set_msg_soaked("Msg you get when you're too soaked.\n"); */
/* set_msg_intoxed("Msg you get when you're too intoxed.\n"); */
/* set_empty_msg("After last charge is used.\n"); */

}

