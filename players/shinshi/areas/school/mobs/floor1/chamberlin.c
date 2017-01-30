inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("chamberlin");
	set_alt_name("teacher");
	set_race("human");
	set_alias("sarah");
	set_short(HIK+"Mrs. Chamberlin, Algebra II Teacher"+NORM);
	set_long("\
	This is Sarah Chamberlin. She is a short, pear-shaped\n\
	female with a very wide smile. She is wearing a green\n\
	low cut shirt that barely shows her clevage. She has\n\
	short blonde hair and a very rosey face.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}