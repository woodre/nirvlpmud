inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("iracki");
	set_alt_name("dennis");
	set_race("human");
	set_alias("counselor");
	set_short(HIW+"Mr. Iracki, Guidance Counselor"+NORM);
	set_long("\
	This is Dennis Iracki. He is a tall, skinny\n\
	man with gray hair on both sides of his head.\n\
	He wears a bright white	shirt with a black tie\n\
	and long black slacks. He is the head of the\n\
	High School guidance counselor committee and\n\
	is fluent in many different languages.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
	set_heal(50, 5);
}