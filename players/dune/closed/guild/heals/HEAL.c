#include "../DEFS.h"
inherit "/obj/generic_heal.c";

status tie()          { return 1; }
status put()          { return 1; }
status send()          { return 1; }
status give()          { return 1; }
status get()          { return 1; }
status drop()         { return 1; }
status sel()         { return 1; }
status sell()         { return 1; }
int query_weight()    { return 1; }
int query_value()     { return 0; }
void reset(int arg) {
  ::reset(arg);
  if(arg) return;

set_name("cyberheal");
add_alias("cyberheal");
add_alias("CYBER_HEAL_ID");
add_alias("heal");
set_short("cyberheal");
set_long("Long Description of heal.\n");

set_type_single("intox");
set_type("intox");
set_msg("What you see when you use it.\n");
set_msg2("What others see when you use it.\n");

set_value(1);
add_cmd("use");
set_heal(50,50);
set_charges(1);
set_intox(100);      /*  intox  soak  stuff  */

/* set_msg_stuffed("Msg you get when you're too stuffed.\n"); */
/* set_msg_soaked("Msg you get when you're too soaked.\n"); */
/* set_msg_intoxed("Msg you get when you're too intoxed.\n"); */
/* set_empty_msg("After last charge is used.\n"); */

}
