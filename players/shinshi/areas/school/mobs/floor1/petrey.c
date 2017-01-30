inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("petrey");
	set_alt_name("teacher");
	set_race("human");
	set_alias("ronald");
	set_short(HIK+"Mr. Petrey, Athletic's Director"+NORM);
	set_long("\
	This is Ronald Petrey. He is a tall, musclar\n\
	man and is in his mid to late forties. He wears\n\
	a black jumpsuit and carries a whistle around his\n\
	neck. His biceps and calf muscles bulge even\n\
	while he just sits at his desk.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}