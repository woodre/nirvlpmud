/*  fire amulet  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("amulet");
set_alias("conflagration amulet");
set_short(HIR+"Conflagration Amulet"+NORM);
set_long(
	"  Closer inspections reveals that this fire-red amulet seems\n"+
	"to have a life of it's own.  Encapsuled within the amulet is \n"+
	"the essence of fire itself... burning relentlessly.\n");

set_ac(2);
set_type("amulet");
set_weight(1);
set_value(1250);
set_arm_light(0);
set_save_flag();
}
