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

set_name("solution");
add_alias("biometric solution");
add_alias("biometric");
add_alias("CYBER_HEAL_ID");
add_alias("bheal");
add_alias("heal");
set_short(""+REV_RED+"Biometric Solution"+OFF+"");
set_long(
""+RED+"A mysterious biometric liquid surrounded by a soft membrane.\n"+
"'Inject'ing a 'biometric' solution could enhance your abilities."+OFF+"\n");

set_type_single("use");
set_type("uses");
set_msg(
"You inject the"+RED+" Boimetric Solution"+OFF+" into your actuators.\n"+
"Your enhancements hum with life.\n");
set_msg2(
"'s enhancements hum to life.\n");

set_value(0);
add_cmd("inject");
set_heal(35,35);
set_charges(5);
set_intox(6);

set_msg_intoxed("The CyberDaemon laughs at you.  A booming voice says 'I think you've had enough.'\n");
set_empty_msg("The solution spills onto the floor, preventing it's use.\n");
}
