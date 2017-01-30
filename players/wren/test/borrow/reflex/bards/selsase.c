#define tp this_player()->query_name()
#define TP this_player()

inherit "/obj/monster";
int n, count;

reset(arg)
{
	::reset(arg);
	if (!arg) {
		set_name("selsase");
		set_short("The spectral figure of a woman");
		set_alias("ghost");
		set_alt_name("woman");
		set_race("spirit");
		set_gender("female");
		set_long
			("You see the spectral figure of the lady who once was Selsase.  She is clad\n"
			 +
			 "in the traditional bardic colors of blue and black, and has flowing silver\n"
			 + "hair and deep silver eyes.\n");
		set_level(20);
		set_ac(50);
		set_wc(13);
		set_hp(1000);
		set_al(-667);
		set_aggressive(0);
		set_chance(20);
		set_spell_dam(random(100));
		set_spell_mess1("The ghost consumes the soul of her foe.");
		set_spell_mess2("The ghost consumes part of your soul!\n" +
						"You feel a dark chill pass through your body.");
	}
}

init()
{
	::init();
	add_action("west", "west");
}

west()
{
	write("Selsase glares at you, and you find that you cannot move.\n");
	return 1;
}
