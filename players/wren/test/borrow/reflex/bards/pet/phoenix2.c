/* <change by="Erasmios" date="2001-07-08"> */
#include "/players/maledicta/ansi.h"
inherit "/players/reflex/guilds/bards/pet/petbase2";

create()
{
	::create();

	set_self_damage(100);
	set_show_health(1);

	set_name("phoenix");
	set_short("A "+HIR+"Fiery Ph"+NORM+RED+"oenix"+NORM);
	set_alt_name("bird");
	set_gender("creature");
	set_race("bird");
	set_long
		("A fiery phoenix with chromatic edged feathers and blazing eyes.\n"
		 +
		 "It has a fifteen foot wing span and large razor sharp claws.\n"
		 +
		 "The phoenix has a small silver band around its left foot.\n");
	set_level(10);
	set_heal(4, 20);
	set_ac(8);
	set_wc(18);
	set_hp(200);
	set_al(1000);
	set_aggressive(0);
	set_chat_chance(3);
	set_a_chat_chance(2);
	load_chat("The phoenix ruffles its feathers.\n");
	load_chat("The phoenix looks at you.\n");
	load_chat("The phoenix stretches its mighty wings.\n");
	load_chat
		("The phoenix looks up with a sparkle in its firey eyes.\n");
	load_a_chat("The phoenix circles its foe.\n");
	load_a_chat("The phoenix rakes its foe with razor sharp claws.\n");
	set_spell_mess1
		("The phoenix flies to its foe and EXPLODES in an inferno of fire.");
	set_spell_mess2
		("The phoenix flies up to you and EXPLODES in an inferno of fire.\nOuch!");
	set_chance(15);
	set_spell_dam(20);
}

is_pet(){ return 1; }

a_short()
{
	return ("A firey phoenix");
}

the_short()
{
	return ("The phoenix");
}

bye_sound()
{
	return ("The phoenix explodes in an inferno of crimson fire.\n\n");
}

sic_sound(str)
{
	return ("The phoenix launches itself towards " + capitalize(str) + ".\n");
}

munch_sound()
{
	return ("The phoenix descends upon the corpse and devours it.\n");
}

die_sound()
{
	return ("The phoenix explodes in an inferno of crimson fire.\n" +
			"You are covered with a light layer of ashes.\n\n");
}

follow_sound()
{
	return ("The phoenix soars off into the sky.\n");
}
/* </change> */
