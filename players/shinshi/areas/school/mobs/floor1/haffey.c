inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("haffey");
	set_alt_name("colleen");
	set_race("human");
	set_alias("nurse");
	set_short(HIG+"Mrs. Colleen Haffey, School Nurse"+NORM);
	set_long("\
	This is Colleen Haffey. She is about five foot,\n\
	ninje inches tall and weighs approximately one\n\
	hundred and ninety-five pounds. She has shoulder\n\
	length dark black hair and beautiful blue eyes.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}