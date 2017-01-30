/*  leather boots  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
reset(arg) {

set_name("boots");
set_alias("riding boots");
set_short(BOLD+"black leather riding boots"+NORM);
set_long(
	"  These knee-high, black leather riding boots provide both leg \n"+
	"and foot protection.  They have been polished to a glossy sheen.\n");

set_ac(2);
set_type("boots");
set_weight(1);
set_value(1000);
set_no_clean(1);
}
