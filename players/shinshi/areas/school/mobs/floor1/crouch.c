inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("crouch");
	set_alt_name("teacher");
	set_race("human");
	set_alias("kim");
	set_short(HIM+"Mrs. Crouch, Special Education Teacher"+NORM);
	set_long("\
	This is Kim Crouch. She is a tall, heavy set\n\
	woman with short curly, black hair. She is\n\
	wearing a hideous dark blue leather jumpsuit\n\
	that shows all of her fat rolls.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}