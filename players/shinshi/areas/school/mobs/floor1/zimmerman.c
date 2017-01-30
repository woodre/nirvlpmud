inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("zimmerman");
	set_alt_name("teacher");
	set_race("human");
	set_alias("jenna");
	set_short(HIK+"Mrs. Zimmerman, Art Teacher"+NORM);
	set_long("\
	This is Jenna Zimmerman. She is a somewhat tall, petite woman with\n\
	long flowing black hair. She is wearing yoga pants which fit tightly\n\
	around her rather nice ass.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_heal(15, 1);
	set_al(-7000);
}