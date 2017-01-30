/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	ec_tunic.c
=-=
=-=	An Elven Child's Tunic
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/armor";
#include "/players/pain/color.h"

reset() {
	set_short("A Child's "+BOLD+GREEN+"Tunic"+END);
	set_long("A well-made, albeit small, green, tightly woven tunic.\n");
	set_ac(1);
	set_weight(1);
	set_type("armor");
	set_value(150);
	set_alias("tunic");
	set_name("tunic");
}

