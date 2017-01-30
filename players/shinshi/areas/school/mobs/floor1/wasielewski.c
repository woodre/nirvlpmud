inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("wasielewski");
	set_alt_name("teacher");
	set_race("human");
	set_alias("gary");
	set_short(HIR+"Mr. Wasielewski, US Government Teacher"+NORM);
	set_long("\
	This is Gary Wasielewski. He is a tall, skinny\n\
	man with short black hair. He wears a light blue\n\
	shirt with a black tie, and long black slacks. He\n\
	is a member of the City Council and teaches two\n\
	different classes: US History and Government.\n");
	set_level(25);
	set_hp(1500 + random (500));
	set_ac(25 + random (5));
	set_wc(30 + random(5));
	set_al(-7000);
	set_heal(30, 1);
	move_object(clone_object("/players/shinshi/areas/school/heals/lifesavers.c"), this_object());
	move_object(clone_object("/players/shinshi/areas/school/heals/lifesavers.c"), this_object());
	set_chat_chance(1);
	load_chat(query_name()+" says, \"Come on guys... Start the drill.\"\n");
	load_chat(query_name()+" says, \"QUIET DOWN, GUYS. We have a lot to do today.\"\n");
	add_spell("gut","	#MN# grabs a knife and attempts to "+HIR+"GUT"+NORM+" you!\n",
					"	#MN# grabs a knife and attempts to "+HIR+"GUT"+NORM+" you!\n",
					15,150,"other|physical");
}