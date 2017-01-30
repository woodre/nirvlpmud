inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;	
	set_name("buxton");
	set_alt_name("faith");
	set_race("human");
	set_alias("counselor");
	set_short(HIW+"Mrs. Buxton, Guidance Counselor"+NORM);
	set_long("\
	This is Faith Buxton. She is a tall, slender\n\
	woman approximately one hundred and seventy-six\n\
	pounds. She has long, flowing blonde hair, with\n\
	light brown highlights that accent her beautiful\n\
	face. She wears a short skirt and a low cut shirt\n\
	that shows off her clevage.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
	set_heal(50, 5);
}