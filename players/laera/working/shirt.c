#include "/players/laera/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("jersey");
set_alias("shirt");
set_short(HIR+"R"+OFF+HIW+"e"+OFF+HIR+"d "+OFF+HIW+"W"+OFF+HIR+"i"+OFF+HIW+"n"+OFF+HIR+"g"+OFF+HIW+"s "+OFF+HIR+"jersey"+OFF);
set_long(
"This shirt, bearing the number 85, was worn by Petr Klima when he\n"+
"played for the Red Wings.  If you look closely, you will see that he\n"+
"has autographed it for the wearer.\n");

set_ac(10);
set_type("armor");
set_weight(1);
set_value(1000);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

