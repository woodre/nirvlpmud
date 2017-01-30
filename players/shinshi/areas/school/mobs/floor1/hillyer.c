inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("steven");
	set_alt_name("teacher");
	set_race("human");
	set_alias("hillyer");
	set_short(HIK+"Mr. Hillyer, Environmental Science Teacher"+NORM);
	set_long("\
	This is Steven Hillyer. He is a tall, skinny built man that is in\n\
	his early fourties. He has short blondish-brown hair which lays\n\
	perfectly on his head.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_heal(35, 1);
	set_al(-7000);
}