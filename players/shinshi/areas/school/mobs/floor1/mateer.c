inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("mateer");
	set_alt_name("teacher");
	set_race("human");
	set_alias("deborah");
	set_short(HIK+"Mrs. Mateer, Calculus Teacher"+NORM);
	set_long("\
	This is Deborah Mateer. She is a tall, very narrow\n\
	shaped female. She has short, frizzy, black hair that\n\
	is slicked back as best as she could. She is wearing\n\
	a white dress shirt with a white jean jacket over top.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}