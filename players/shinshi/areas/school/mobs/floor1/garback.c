inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("garback");
	set_alt_name("teacher");
	set_race("human");
	set_alias("meredith");
	set_short(HIK+"Ms. Garback, Spanish Teacher"+NORM);
	set_long("\
	This is Meredith Garback. She is a stout, heavy\n\
	set female with shoulder length black hair. She\n\
	has on way too much makeup, especially lipstick.\n\
	She also serves as the schools co-head swim coach.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}