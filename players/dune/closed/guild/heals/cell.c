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

set_name("power cell");
add_alias("cell");
add_alias("CYBER_HEAL_ID");
add_alias("heal");
set_short(""+YELLOW+"Power Cell"+OFF+"");
set_long(
""+YELLOW+"A cylindrical devise that draws energy directly from the\n"+
"CyberDaemon.  A small cord can be drawn and retracted from\n"+
"a panel on the side.  You may 'plug' the power cell into\n"+
"your matrix to recoup some of it's power."+OFF+"\n");

set_type_single("use");
set_type("uses");
set_msg(
"You flip the switch on the power cell and are filled with "+RED+"E"+GREEN+"N"+BROWN+"E"+YELLOW+"R"+BLUE+"G"+MAGENTA+"Y"+OFF+".\n");
set_msg2(
" flips a switch on the power cell and is filled with "+RED+"E"+GREEN+"N"+BROWN+"E"+YELLOW+"R"+BLUE+"G"+MAGENTA+"Y"+OFF+".\n");

set_value(0);
add_cmd("plug");
set_heal(50,50);
set_charges(3);
set_soak(8);
set_stuff(8);

set_msg_stuffed("The power cell shorts out.  You gain no energy.\n");
set_msg_soaked("The power cell shorts out.  You gain no energy.\n");
set_empty_msg("The overloaded power cell explodes from overuse.\n");
}
