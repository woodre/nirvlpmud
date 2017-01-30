#include "/sys/lib.h"
#include <ansi.h>

inherit "/obj/monster";

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("student");
	set_alt_name("shinshi_student");
	set_race("human");
	set_alias("shinshi_female_student");
	set_short("A "+HIM+"Female"+NORM+"Student");
	set_long("\
	This is a young girl wearing a very short\n\
	skirt. She has a shirt on that is very low\n\
	cut and shows off her clevage.\n");
	set_level(15);
	set_hp(250);
	set_ac(12);
	set_wc(20);
	set_al(7000);
	enable_commands();
   
	remove_call_out("make_random_move");
	call_out("make_random_move", 1);
}

make_random_move()
{
	int n;
	
	if(!this_object()->query_attack())
	{
		n = random(10);
		
		if (n == 0)
		command("up");
		if (n == 1)
		command("down");
		if (n == 2)
		command("north");
		if (n == 3)
		command("east");
		if (n == 4)
		command("south");
		if (n == 5)
		command("west");
		if (n == 6)
		command("northwest");
		if (n == 7)
		command("northeast");
		if (n == 8)
		command("southwest");
		if (n == 9)
		command("southeast");
	}
	
	remove_call_out("make_random_move");
	call_out("make_random_move", 1);
}