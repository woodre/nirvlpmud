inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("barbara");
	set_alt_name("mclaughlin");
	set_race("human");
	set_alias("secretary");
	set_short(HIW+"Mrs. McLaughlin, Office Secretary"+NORM);
	set_long("\
	This is Barbara McLaughlin. She is a larger, heavier woman\n\
	with long, flowing, brown-blonde hair. She has her hair tied\n\
	up into a tight ponytail. She is wearing a dark blue dress\n\
	with white flowers.\n");
	set_level(1);
	set_hp(1);
	set_ac(1);
	set_wc(1);
	set_heal(999999, 1);
}