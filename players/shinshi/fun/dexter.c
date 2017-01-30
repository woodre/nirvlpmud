inherit "/obj/monster";

#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
	::reset(arg);
	if(arg) return;
	set_name("dexter");
	set_alt_name("douglas");
	set_race("human");
	set_alias("freakazoid");
	set_short(HIC+"Dexter Douglas"+NORM);
	set_long("\
	Gaining his abilities from a computer bug (becoming absorbed\n\
	into his computer and instantly gaining all the information on\n\
	the Internet), Freakazoid has enhanced strength and endurance,\n\
	extraordinary speed, agility, and negligible amounts of sanity.\n\
	These changes make him a powerful and fearsome force for upholding\n\
	freedom and righteousness, unless he gets distracted by something\n\
	like a bear riding a motorcycle.\n");
	/* Description taken from http://en.wikipedia.org/wiki/Freakazoid!#Background */
	set_level(23);
	set_hp(800 + random (200));
	set_ac(24 + random (10));
	set_wc(40 + random(10));
	set_al(7000);
	set_chat_chance(1);
	load_chat(query_name()+" logs on his computer to check his e-mail.\n");
	add_spell("chuck","#MN# throws his computer monitor at you!\n",
		"#MN# $HK$chucks$N$ his computer monitor at #TN#'s head.\n",
	20,125,"other|physical");
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
        
  if(this_object()->query_hp() < (this_object()->query_mhp() / 2))
  {
    tell_room(environment(this_object()),
      "Dexter Douglas screams, \"I'm FREAKIN' OUT!\"\n");
    move_object(clone_object("/players/shinshi/fun/freakazoid.c"), environment(this_object()));
    destruct(this_object());
	}
}