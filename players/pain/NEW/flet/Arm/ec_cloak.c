/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	ec_cloak.c
=-=
=-=	An Elven Child's Cloak
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/armor";
#include "/players/pain/color.h"

reset() {
	set_short("A Child's "+BOLD+GREEN+"Cloak"+END);
	set_long("A well-made, albeit small, green, tightly woven cloak.\n");
	set_ac(1);
	set_weight(1);
	set_type("armor");
	set_value(150);
	set_alias("cloak");
	set_name("cloak");
}

