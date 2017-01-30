/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	eg_cloak.c
=-=
=-=	An Elven Guard's Cloak
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/armor";
#include "/players/pain/color.h"

reset() {
	set_short("A dark "+BOLD+GREEN+"Elven"+END+" Cloak");
	set_long("A handsomely made, hand-woven "+BOLD+GREEN+"Elven"+END+" Cloak.\n"+
		"This cloak is made of a material that shimmers like starlight,\n"+
		"surrounding you with protection from sight and harm.\n");
	set_weight(2);
	set_ac(1);
	set_type("misc");
	set_alias("cloak");
	set_name("cloak");
	set_value(300+random(300));
}
