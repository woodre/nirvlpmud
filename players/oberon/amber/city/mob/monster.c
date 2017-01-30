#include <ansi.h>
inherit "/obj/monster";

 reset(arg) {
	object sack;
	object obj;

	::reset(arg);
	if(arg) return;

	set_chat_chance(3);

	SetMultipleIds( ({ "townsmen", "man", "townsman", "biker",  }) );
	set_name("guard");
	set_race("human");
	set_short("Townsmen Guard");
	set_long(
		"A man in his late 30's who has no remarkable features. He looks like a\n\
		regular American biker guy with a long beard and dressed in leather.\n\
		He is a bit thin for the biker style but he looks pretty serious.\n");
	set_gender("male");
	set_level(20);
	set_hp(400 + random(200));
	set_wc(30);
	set_ac(17);
	set_aggressive(0);
	set_al(-100);

	load_chat("Guard says: 'Keep moving man, we aren't the welcoming committee.'\n");
	load_chat("Guard scowls as he looks past you.\n");
	load_chat("Guard says: 'I'd stay out of the forest if you like being alive.'\n");
	load_chat("Guard says: 'Lucas will buy any crap you find on dead Walkers.'\n");
	load_chat("Guard says: 'Start any trouble and Oak will gut you and let you\n\
		turn and then he'll kill you again.'\n");
	load_chat("Guard stops and strokes his beard.\n");
	load_chat("Guard says: 'We aren't overrun with biters, just trying to keep\n\
		pukes like you out of town.\n");
	load_chat("Guard says: 'Dismembering a Walker corpse is sick, man.'\n");

	move_object(clone_object("/players/dragnar/WalkingDead/armor/ammo_belt"), this_object());
	init_command("wear belt");
	move_object(clone_object("/players/dragnar/WalkingDead/armor/swat_helmet"), this_object());

	init_command("wear helmet");
  
  add_spell("short_range_attack",
    "#MN# quickly taps a double burst from his $HC$Glock$N$ right at your face!\n",
    "#MN# quickly taps a double burst from his $HC$Glock$N$ right at #TN#'s face!\n",
    20,20-30,"physical", 0 );

	move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
}

init() {
	::init();
}

heart_beat() {
	::heart_beat();
}

monster_died() {
	object corpse;
	object item;
	corpse = present( "corpse", environment() );
	if(corpse) {
		item = present( "kill_check_object", corpse );
		if( item )
			destruct( item );
	}
	return 0; 
}
