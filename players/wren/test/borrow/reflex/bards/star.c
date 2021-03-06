#define tp this_player()->query_name()
#define TP this_player()

inherit "/obj/monster";
int n, count;
object ob, ob2;

reset(arg)
{
	ob = clone_object("/players/saber/stuff/cards.c");
	move_object(ob, this_object());
	ob2 = clone_object("/players/reflex/guilds/bards/bard_mark.c");
	move_object(ob2, this_object());
	::reset(arg);
	if (!arg) {
		set_name("star");
		set_short("A young girl");
		set_alias("girl");
		set_race("human");
		set_gender("female");
		set_long("Star is the Occult and Lore Mistress of the Bards.\n" +
				 "She is a young girl of perhaps seven, with deep blue eyes and and silky\n"
				 +
				 "blond hair which falls down around her shoulders.  Star is wearing black\n"
				 +
				 "nickers and a loose white blouse with silver trim.  She is unbelievably\n"
				 + "cute.\n");
		set_level(19);
		set_ac(30);
		set_wc(10);
		set_hp(475);
		set_al(900);
		set_aggressive(0);
		set_chat_chance(3);
		set_a_chat_chance(20);
		load_chat("Star shuffles her cards.\n");
		load_chat("Star looks up at you and smiles.\n");
		load_chat("Star asks \"\Have you seen Christopher?\"\n");
		load_chat
			("Star deals out the cards and observes their positions.\n");
		load_chat
			("Star says \"\I wish I hadn't died so many times...\"\n");
		load_chat
			("Star deals out the cards, observes them and nods to herself.\n");
		load_chat("Star looks up at you and winks.\n");
		load_chat("Star splashes you with some water.\n");
		load_chat("Star dangles her feet in the pool.\n");
		load_chat("Star looks into the pool of water.\n");
		load_chat
			("Star strips of her clothing and goes for a brief dip in the pool.\n");
		load_chat("Star sips some water from the pool.\n");
		load_a_chat("Star dodges the attack.\n");
		load_a_chat("Star traces mystic symbols in the air.\n");
		load_a_chat("Star blasts her foe with magical fire.\n");
		load_a_chat("Star nimbly dodges the blow.\n");
		load_a_chat("Star whispers mystic soundind whispers.\n");
		set_chance(25);
		set_spell_dam(random(60));
		set_spell_mess1("Star whispers the TRUE NAME of her foe.");
		set_spell_mess2("Star whispers your true name!\n" +
						"You feel a dark chill through your soul.");

		set_object(this_object());
		set_function("hugs");
		set_type("hug");
		set_match("");
		set_function("hi_there");
		set_type("arrives");
		set_match("");
	}

}

notify(str)
{
	say(str);
	write(str);
}

hugs(str)
{
	string who;

	if (sscanf(str, "%s hugs", who) == 1) {
		if (who == "star" || who == "Star")
			return;
		notify("Star hugs " + who + ".\n");
	}
}

hi_there(str)
{
	string who;

	if (sscanf(str, "%s arrives.", who) == 1) {
		notify("Star smiles at " + who + ".\n");
	}
}

init()
{
	::init();
	add_action("new_sp_say", "say");
	add_action("new_sp_say", "'");
	add_action("new_sp_say", ";");
	add_action("new_give", "give");
}

new_sp_say(str)
{
	object ob, target;
	int temp, number;

	ob = present("instrument", this_player());

	if (ob->query_bard_level() == 2) {
     if(ob->query_approval() == 3){
		if (sscanf(str, "%d", temp) == 1) {
        	number =
				(TP->query_attrib("int")) + (TP->query_attrib("mag")) +
				(TP->query_attrib("pie")) + (TP->query_attrib("wil"));

			if (temp == number) {
				advance();
			   }
        }
		}
	}
}


advance()
{
	say("Star smiles at " + tp +
		".\nVery well done, brave bard!  You have found the number of your\n"
		+
		"cosmic balance.  That is the first step towards personal power.\n"
		+ "\nI think you deserve to be promoted.\n\n" + tp +
		" is now Bard Level 3!\n\n");
	ob = present("instrument", this_player());
	ob->set_bard_level("3");
	ob->set_bard_xp("2000");
	return 1;
}

new_give(str)
{
	object OB, ORB;

	if (str == "orb to star" || str == "ebony orb to star"
		|| str == "orb to girl" || str == "ebony orb to girl") {
		if ((this_player()->query_level()) < 14) {
			write("You must be level 14 to do this trial.\n");
			return 1;
		}
		OB = present("instrument", this_player());
		if (OB->query_bard_level() != 6) {
			write("You must be bard level 6 to do this trial.\n");
			return 1;
		}
		if (!present("orb", this_player())) {
			write("You don't have the orb.\n");
			return 1;
		}
		ORB = present("orb", this_player());
		destruct(ORB);
		say("\n\nStar takes the ebony orb and smashes it.\n\n");
		OB->set_bard_level("7");
		OB->set_bard_xp("32000");
		say("You are now bard level 7!\n" +
			"\nStar teaches you the Cantrip Strand.\n\n" +
			"Star teaches you the Requiem of the Falling Stars.\n\n" +
			"Star teaches you the Song of Illusion.\n\n");
		return 1;
	}
}
