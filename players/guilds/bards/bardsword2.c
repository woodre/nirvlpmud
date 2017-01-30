#define tp this_player()->query_name()
#define ATT attacker->query_name()
/* <change by="Erasmios" date="2001-05-25> */
ROM(str)
{
	tell_room(environment(this_player()), "\n" + str);
}

/* </change> */
int w, n, ahp;

inherit "obj/weapon.c";

reset(arg)
{
	::reset(arg);
	if (arg)
	return;
	set_name("bardsword");
	set_short("A Crystal Bardsword");
	set_long("An ivory white longsword of gleaming crystal.\n" +
		"It is very light, and has a wicked edge to it.\n" +
	"There is a Bardic rune on the hilt.\n");
	set_class(18);
	set_weight(2);
	set_value(2000);
	set_hit_func(this_object());
}

weapon_hit(attacker)
{
	w = random(90);
	
	if (w < 36) {
		
		if (w < 2) {
			write
			("The Bardsword gleams with a pure white fire as it cleaves through your foe.\n");
			write(capitalize(attacker->query_real_name()) +
			" staggers.\n");
			say(tp + "'s Bardsword gleams with a pure white fire as " +
				this_player()->query_pronoun() + " cleaves through " +
				this_player()->query_possessive() + " foe.\n" +
			capitalize(attacker->query_real_name()) + " staggers.\n");
		}
		if (w == 2) {
			ROM(" " + tp +
			"'s sword sings \"The Ride of the Valkyries\"n\n");
		}
		if (w == 3) {
			ROM("  " + tp +
			"'s sword sings \"March to the Scaffold\" from Symphonie Fantastique\n\n");
		}
		if (w == 4) {
			ROM("  " + tp +
			"'s sword sings \"The Hut on Fowls Legs\" from Pictures at an Exhibition\n\n");
		}
		if (w == 5) {
			ROM("  " + tp +
			"'s sword sings the conclusion to \"The 1812 Overture\"\n\n");
		}
		if (w == 6) {
			ROM("  " + tp +
			"'s sword sings \"Allegro Molto Vivace\" from Symphony No.6 \"Pathetique\"n\n");
		}
		if (w == 7) {
			ROM("  " + tp +
			"'s sword sings the \"Polovtslan Dance\" from Prince Igor.\n\n");
		}
		if (w == 8) {
			ROM("  " + tp +
			"'s sword sings the \"Hungarian March\" from The Damnation of Faust\n\n");
			this_player()->heal_self(10);
		}
		if (w == 9) {
			ROM("  " + tp +
			"'s sword sings \"Mars, The Bringer of War\" from The Planets\n\n");
			attacker->heal_self(-10);
		}
		if (w == 10) {
			ROM("  " + tp +
			"'s sword sings \"Prelude to Act III\" from the Lohengrin\n\n");
		}
		if (w == 11) {
			ROM("  " + tp +
			"'s sword sings \"Infernal Dance\" from The Firebird\n\n");
		}
		if (w == 12) {
			ROM("  " + tp +
			"'s sword sings \"Sturmisch Bewegt\" from \"Titan\"n\n");
		}
		if (w == 13) {
			ROM("  " + tp +
			"'s sword sings \"O Fortuna\" from Carmina Burana\n\n");
			this_player()->heal_self(5);
		}
		if (w == 14) {
			ROM("  " + tp +
			"'s sword sings \"Fortune plango vulnera\" from Camarina Burana\n\n");
		}
		if (w == 15) {
			ROM("  " + tp +
			"'s sword sings \"Ella mi fu rapita\" from Rigoletto\n\n");
		}
		if (w == 16) {
			ROM("  " + tp +
			"'s sword sings \"Allegro Con Brio\" from Symphony No. 25\n\n");
		}
		if (w == 17) {
			ROM("  " + tp +
			"'s sword sings \"Don Giovanni, A Cenar Teco\"!!!\n\n");
			attacker->heal_self(-5);
		}
		if (w == 18) {
			ROM("  " + tp +
			"'s sword sings \"Dies Irae\" from Requiem, K 626\n\n");
		}
		if (w == 19) {
			ROM("  " + tp +
			"'s sword sings \"Rex Tremendae\" from Requiem, K 626\n\n");
		}
		if (w == 20) {
			ROM("  " + tp +
			"'s sword sings \"Toccata and Fuge in D-Minor\"\n\n");
		}
		if (w == 21) {
			ROM("  " + tp +
			"'s sword sings the Act 1 Chorus from \"The Bartered Bride\"\n\n");
		}
		if (w == 22) {
			ROM("  " + tp +
			"'s sword sings the Servants Chorus from \"Don Pasquale\"\n\n");
		}
		if (w == 23) {
			ROM("  " + tp +
			"'s sword sings \"Chorus of the Warriors\" from Norma\n\n");
			attacker->heal_self(-5);
		}
		if (w == 24) {
			ROM("  " + tp +
			"'s sword sings the Soldiers Chorus from \"Faust\"\n\n");
		}
		if (w == 25) {
			ROM("  " + tp +
			"'s sword sings \"Carmen, les voici!\" from Carmen\n\n");
		}
		if (w == 26) {
			ROM("  " + tp +
			"'s sword sings the Gypsy Chorus from \"Il Tovatore\"\n\n");
		}
		if (w == 27) {
			ROM("  " + tp +
			"'s sword sings \"Gli avredi festivi\" from Nabucco!!!\n\n");
		}
		if (w == 28) {
			ROM("  " + tp +
			"'s sword sings \"Allegro con brio\" from Symphony No.5 in C minor\n\n");
		}
		if (w == 29) {
			ROM("  " + tp +
			"'s sword sings the \"Moonlight\" Sonata, Op.27 in C sharp minor!\n\n");
			this_player()->heal_self(5);
		}
		if (w == 30) {
			ROM("  " + tp +
			"'s sword sings the \"Choral\" Symphony No.9 in D minor\n\n");
		}
		if (w == 31) {
			ROM("  " + tp +
			"'s sword sings the \"Fantasie-Impromptu\" from Impromptu Nr.4 cis-Moll 66\n\n");
		}
		if (w == 32) {
			ROM("  " + tp +
			"'s sword sings the Allegretto from \"Faust\"n\n");
		}
		if (w == 33) {
			ROM("  " + tp +
			"'s sword sings \"Gira la cote\" from the Turandot\n\n");
		}
		if (w == 34) {
			ROM("  " + tp +
			"'s sword sings \"Non piangere, Liu!\" from the Turandot\n\n");
			this_player()->heal_self(3);
		}
		if (w == 35) {
			ROM("  " + tp +
			"'s sword sings \"Ah! per l'ultima volta\" from the Turandot\n\n");
		}
		
		return 6;
	}
	
	return;
}

init()
{
	::init();
	add_action("new_wield", "wield");
	add_action("new_wield", "ready");
}

new_wield(str)
{
	if (str == "bardsword") {
		if (this_player()->query_guild_name() != "bard") {
			write("You are not a Bard!\n");
			return 1;
		}
		write
		("\nYou feel a surge of power as you wield your BARDSWORD.\n\n");
		say("\n" + tp + " is surrounded by a blue aura as " +
		this_player()->query_pronoun() + " wields a BARDSWORD.\n\n");
		return 0;
	}
}
