inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("hejl");
	set_alt_name("teacher");
	set_race("human");
	set_alias("elizabeth");
	set_short(HIK+"Mrs. Hejl"+NORM);
	set_long("\
	This is Elizabeth Hejl. She is a short\n\
	and plump older woman that looks to be\n\
	in her low fifties. She has dark brown\n\
	hair that curls. She has a nasty glare\n\
	on her face.\n");
	set_level(23);
	set_hp(800 + random (200));
	set_ac(24 + random (10));
	set_wc(40 + random(10));
	set_al(-7000);
	set_chat_chance(1);
	load_chat(query_name()+" says, \"Where's your pass, boyus?\"\n");
	load_chat(query_name()+" says, \"Don't start with me, girlie-girl! Go to the office NOW!\"\n");
	add_spell("chuck","#MN# $HK$chucks$N$ a book at your head.\n",
		"#MN# $HK$chucks$N$ a book at #TN#'s head.\n",
	20,125,"other|physical");
}

second_life()
{
	object corpse;
	
	if(!environment()) return;
	
    tell_room(environment(this_object()),
      "Mrs. Hejl screams loudly and transforms into a"+HIK+" Large Demon "+NORM+".\n");
    move_object(clone_object("/players/shinshi/areas/school/mobs/floor1/hejldemon.c"), environment(this_object()));
    
    corpse = present("corpse", environment(this_object()));
    if(corpse) destruct(corpse);
}