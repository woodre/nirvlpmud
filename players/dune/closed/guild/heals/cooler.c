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

set_name("liguified circuit cooler");
add_alias("cooler");
add_alias("circuit");
add_alias ("circuit cooler");
add_alias("CYBER_HEAL_ID");
add_alias("heal");
set_short("Liquified Circuit Cooler");
set_long(
"A small system attached directly to your power systems.  This\n"+
"device can be used once to reset your matrix and cool down\n"+
"your power systems.  You may 'patch' the circuit cooler into\n"+
"your matrix at any time.\n");

set_type_single("patch");
set_msg(
"Your internal systems are rejuvenated.\n");
set_msg2(
" draws massive amounts of energy from the CyberDaemon.\n");

set_value(0);
add_cmd("patch");
set_heal(1000,1000);
set_charges(1);
set_soak(0);
set_stuff(0);
}
