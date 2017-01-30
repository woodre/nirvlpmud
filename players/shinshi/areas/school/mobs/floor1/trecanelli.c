inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("trecanelli");
	set_alt_name("teacher");
	set_race("human");
	set_alias("joshua");
	set_short(HIK+"Mr. Trecanelli, Wood Shop Teacher"+NORM);
	set_long("\
	This is Joshua Trecanelli. He is a tall, skinny, male with clothes\n\
	that barely fit him. He has short, black hair that lies flat on his\n\
	head. He is wearing a white dress shirt with a striped red and black\n\
	tie. He looks very white and nerdy.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_heal(35, 1);
	set_al(-7000);
}