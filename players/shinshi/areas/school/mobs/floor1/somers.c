inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("somers");
	set_alt_name("teacher");
	set_race("human");
	set_alias("kathleen");
	set_short(HIK+"Mrs. Somers, Foods Teacher"+NORM);
	set_long("\
	This is Kathleen Somers. She is a tall, skinny woman that is in\n\
	her late thirties or early fourties. She has short, spikey, blonde\n\
	hair that has bits of dark brown highlights in it. She has blue\n\
	eyes that seem to pierce your soul.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
}