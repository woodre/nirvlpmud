inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("joshua");
	set_alt_name("teacher");
	set_race("human");
	set_alias("thompson");
	set_short(HIK+"Mr. Thompson, Algebra II Teacher"+NORM);
	set_long("\
	This is Joshua Thompson. He is a tall, skinny built man that is in\n\
	his mid to late fourties. He has short blondish brown hair that is\n\
	spiked up. He has a very feminine voice.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_heal(35, 1);
	set_al(-7000);
}