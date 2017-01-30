inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("kathleen");
	set_alt_name("teacher");
	set_race("human");
	set_alias("mader");
	set_short(HIK+"Ms. Mader, French Teacher"+NORM);
	set_long("\
	This is Kathleen Mader. She is a ugly, rather\n\
	short, plumpy lady. She is wearing a pair of\n\
	khaki pants that show off her hairy legs. She\n\
	has long, black, curly hair that somewhat covers\n\
	her chubby, rosey-red cheeks.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}