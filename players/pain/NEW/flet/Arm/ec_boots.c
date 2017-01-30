/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	ec_boots.c
=-=
=-=	A pair of Elven Children's boots
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <ansi.h>
inherit "/obj/armor";

reset() {
	set_short("A Child's pair of "+BOLD+GREEN+"Boots"+NORM);
	set_long("A well-made, albeit small, pair of children's boots.\n");
	set_ac(1);
	set_weight(1);
	set_type("boots");
	set_value(150);
	set_alias("boots");
	set_name("boots");
}
