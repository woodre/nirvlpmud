inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("fulkrod");
	set_alt_name("teacher");
	set_race("human");
	set_alias("margaret");
	set_short(HIK+"Mrs. Fulkrod, Geometry Teacher"+NORM);
	set_long("\
	This is Margaret Fulkrod. She is a short, pudgy\n\
	female with short, curly gray hair. She wears\n\
	large glasses that look like they can pick up\n\
	cable from a satellite. She wears her pants up\n\
	as close to her chest as possible.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}