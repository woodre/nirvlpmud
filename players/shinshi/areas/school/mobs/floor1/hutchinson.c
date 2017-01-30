inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("hutchinson");
	set_alt_name("teacher");
	set_race("human");
	set_alias("kenneth");
	set_short(HIK+"Mr. Hutchinson, Algebra Teacher"+NORM);
	set_long("\
	This is Kenneth Hutchinson. He is a tall, skinny\n\
	male with short black hair with a receding hair line.\n\
	He has a white dress shirt with a blue and black tie\n\
	with the eBay logo on it.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
	move_object(clone_object("/players/shinshi/areas/school/heals/lifesavers.c"), this_object());
	move_object(clone_object("/players/shinshi/areas/school/heals/lifesavers.c"), this_object());
}