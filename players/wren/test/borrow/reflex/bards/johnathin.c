inherit "/obj/monster";
int n, count, COUNT;
object ob;

reset(arg)
{
	ob = clone_object("/players/saber/weapons/rapier.c");
	move_object(ob, this_object());
	::reset(arg);
	if (!arg) {
		set_name("johnathin do oro");
		set_short("A Young Swashbuckler");
		set_alt_name("johnathin");
		set_alias("swashbuckler");
		set_race("human");
		set_long
			("Johnathin de Oro is a young swashbuckler dressed in fine clothing who wears\n"
			 +
			 "his raven brown hair fashionably long.  He has a mischievous sparkle in his\n"
			 +
			 "eyes and a loose grin on his face.  Johnathin de Oro is reputed to know almost\n"
			 +
			 "everything that there is to know about the city of Ryllian.  He is also one of\n"
			 + "the best bladesmen in the city.\n");
		set_gender("male");
		set_level(19);
		set_ac(16);
		set_wc(28);
		set_hp(475);
		set_al(900);
		set_aggressive(0);
		set_chat_chance(1);
		set_a_chat_chance(20);
		load_chat("Johnathin de Oro smiles slightly to himself.\n");
		load_chat("Johnathin de Oro orders a drink from the bartender.\n");
		load_chat("Johnathin de Oro glances over at you.\n");
		load_chat
			("Johnathin de Oro whispers something to a passing barmaid.\n");
		load_chat
			("Johnathin de Oro waves to somebody in the common room.\n");
		load_chat("Johnathin de Oro says: Don't I know you?\n");
		load_chat
			("Johnathin de Oro says: I know almost everything about Ryllian.\n");
		load_chat
			("Johnathin de Oro says: You should ask me a question.\n");
		load_a_chat("Johnathis de Oro smiles wickedly.\n");
		load_a_chat("Johnathin de Oro parries a blow.\n");
		load_a_chat
			("Johnathin de Oro punches you in the face with the pommel of his sword.");
		load_a_chat
			("Johnathin de Oro says: You cannot be this stupid!  Give up now!\n");
		load_a_chat("Johnathin de Oro kicks his foe in the solar plex.\n");
		load_a_chat("Johnathin de Oro punches his foe in the face.\n");
		load_a_chat("Johnathin de Oro dodges a wild swing.\n");
		set_chance(15);
		set_spell_dam(random(40));
		set_spell_mess1("Johnathin impales his foe.");
		set_spell_mess2("Johnathin impales you with his rapier.\n" +
						"You feel the blade extending from your back.");

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
		if (who == "johnathin" || who == "Johnathin")
			return;
		notify("Johnathin hugs " + who + ".\n");
	}
}

hi_there(str)
{
	string who;

	if (sscanf(str, "%s arrives.", who) == 1) {
		notify("Johnathin nods at " + who + ".\n");
	}
}

init()
{
	::init();
	add_action("new_sp_say", "say");
	add_action("new_sp_say", "'");
	add_action("new_sp_say", ";");
	add_action("sing_quest", "sing");
}

new_sp_say(str)
{
	object from, target;
	string temp, temp2;
	int number;

	if (sscanf(str, "%s %s %d", temp, temp2, number) < 4) {
		if (temp == "bard") {
			if (temp2 == "task") {
				if (number == 1) {
					tell_room(environment(this_object()),
							  capitalize(this_player()->query_name()) +
							  " says: " + str + "\n");
					say("Johnathin says \"\Play me 'Hay nonny nonny'.  I haven't heard that in a while.\"\n");
					count = 0;
					return 1;
				}
				say("Johnathin says \"\You should check the lore room for info on the bard quests.\"\n");
				return 1;
			}
			say("Johnathin says \"\The bardic guild is upstairs.\"\n");
			return 1;
		}
	}
	if (sscanf(str, "%s", temp) == 1) {
		if (temp == "scroll") {
			COUNT = 0;
			if ((this_player()->query_level()) < 14) {
				return 1;
			}
			if (!present("instrument", this_player())) {
				return 1;
			}
			target = present("instrument", this_player());
			if ((target->query_bard_level()) != 7) {
				return 1;
			}
			if (!present("pearl", this_player())) {
				NOPE();
			}
			if (!present("wine", this_player())) {
				NOPE();
			}
			if (!present("bloodstone", this_player())) {
				NOPE();
			}
			if (!present("medallion", this_player())) {
				NOPE();
			}
			if (COUNT < 1) {
				say("Johnathin says \"\Here you go " +
					this_player()->query_name() + ".\"\n" +
					"Johnathin hands " + this_player()->query_name() +
					" a scroll.\n\n");
				move_object(clone_object
							("/players/reflex/guilds/bards/scroll6.c"),
							this_player());
				return 1;
			}
		}
	}
}

NOPE()
{
	write
		("Johnathin says \"\You must have all 4 items to make the scroll.\"\n");
	COUNT = COUNT + 1;
	return 1;
}

sing_quest(str)
{
	string song, verse;
	string temp, temp2, temp3;
	object inst;

if(!str){
       write("Sing what?\n");
       return 1;
       }
	if (!present("instrument", this_player())) {
		write("You do not know any bardic songs.\n");
		return 1;
	}

	ob = present("instrument", this_player());

	if (ob->query_bard_level() != 1) {
		write("You must be bard level one for this trial.\n");
		return 1;
	}

	if (sscanf(str, "%s %s", song, verse) == 2) {

		if (song == "1") {

			if (verse == "1") {
				if (count == 0) {
					count = count + 1;
				} else {
					wrong();
				}
			}
			if (verse == "2") {
				if (count == 1 || count == 3) {
					count = count + 1;
				} else {
					wrong();
				}
				if (count == 4) {
					finish();
				}
			}
			if (verse == "3") {
				if (count == 2) {
					count = count + 1;
				} else {
					wrong();
				}
			}

		}
	}

}

wrong()
{
	write("Johnathin looks over at you and shakes his head.\n" +
		  "You need to play the verses in order.\n" +
		  "\nTry again from the beginning of the song.\n");
	count = 0;
	return 1;
}

finish()
{
	object obj;

	say("Johnathin looks over at " + this_player()->query_name() +
		" and smiles.\n");
	write("Johnathin smiles at you.\n" +
		  "Johnathin whispers: That was very well done.  I think you deserve a promotion.\n"
		  + "\nYou are now bardic guild level 2!\n\n");
	obj = present("instrument", this_player());
	obj->set_bard_level("2");
	obj->set_bard_xp(1000);
	return 1;
}
