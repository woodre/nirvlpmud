/* <change by="Erasmios" date="2001-07-08"> */
inherit "/players/guilds/bards/pet/petbase";

create()
{
	::create();

	set_self_damage(36);
	set_show_health(1);

	set_name("drake");
	set_short("A small black drake");
	set_alt_name("bird");
	set_gender("creature");
	set_race("bird");
	set_long
		("A small drake with small black scales and bright green eyes.\n"
		 +
		 "It has a tiny red tongue and small talons at the end of its wings.\n"
		 +
		 "The drake has a small silver band around its left foot.\n");
	set_level(7);
	set_heal(4, 20);
	set_ac(5);
	set_wc(15);
	set_hp(175);
	set_al(400);
	set_aggressive(0);
	set_chat_chance(3);
	set_a_chat_chance(2);
	load_chat("The drake preens.\n");
	load_chat("The drake looks up with whirling green eyes.\n");
	load_chat("The drake hisses.\n");
	load_chat("The drake licks its tiny white fangs.\n");
	load_chat("The drake flies about the chamber.\n");
	load_chat("The drake hums softly to itself.\n");
	load_chat("The drake looks at you.\n");
	load_a_chat("The drake circles its foe.\n");
	set_spell_mess1("The drake breaths fire upon its foe.");
	set_spell_mess2("The drake breaths fire upon you!");
	set_chance(15);
	set_spell_dam(15);
}

a_short()
{
	return "A black drake";
}

the_short()
{
	return "The drake";
}

bye_sound()
{
	return ("The drake does an aerial loop and flies off into the sky.\n");
}

sic_sound(str)
{
	return ("The drake roars and flies towards " + capitalize(str) + ".\n");
}

munch_sound()
{
	return ("The drake flies down to the corpse and rips out its throat.\n" +
			"The drake drinks the blood with a tiny red tongue.\n");
}

follow_sound()
{
	return ("The drake does an aerial loop and flies after its master.\n");
}

/* </change> */
