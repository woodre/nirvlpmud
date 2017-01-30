inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("green");
	set_alt_name("teacher");
	set_race("human");
	set_alias("martha");
	set_short(HIK+"Mrs. Green, Home Economics Teacher"+NORM);
	set_long("\
	This is Martha Green. She is a short, rather plump\n\
	woman in her mid to late seventies. She wears a thick\n\
	pair of glasses that look as if they could pick up\n\
	satellite radio. She has a long black dress on that\n\
	brushes the ground under her as she walks.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}