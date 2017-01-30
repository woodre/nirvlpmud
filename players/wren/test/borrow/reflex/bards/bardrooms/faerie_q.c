#define ACE find_living("faerie")
#define tp this_player()->query_name()
/* <change by="Erasmios" date="2001-05-24> */
/* abusing a slightly quirky preprocessor */
/*#define ROM tell_room(environment(ACE), "\nThe Faerie Queen says:\n*/
/* </change> */
string NAME, SIB;
object OB;

inherit "room/room";

int t, count, count2, count3;

reset(int arg)
{
	if (!present("faerie")) {
		move_object(clone_object("/players/reflex/guilds/bards/f_mark.c"),
					this_object());
	}
	count = 0;
	count2 = 0;
	count3 = 0;
	if (!arg) {
		set_light(1);
		short_desc = "Faerie Court";
		long_desc =
			"Rising before you, like a the gossamer fragments of a midsummer dream, is the\n"
			+
			"Castle of the Arcadia Gateway.  The castle appears to have been constructed\n"
			+
			"from a scintillating rainbow of crystal, with impossibly thin towers rising up\n"
			+
			"towards the twilight of the setting sun.  You stand in a glade, surrounded on\n"
			+ "all sides by moss covered boulders and whispering trees.\n";

		items = ({
			"trees",
			"You are too enchanted by the faerie court to look at trees",
			"boulders",
			"You are too enchanted by the faerie court to look at boulders",
			"crystal",
			"You are too enchanted by the faerie court to look at",
			"towers",
			"You are too enchanted by the faerie court to look at towers",
			"sun",
			"You are too enchanted by the faerie court to look at the sun",
			"castle",
			"You are too enchanted by the faerie court to look at the castle",
			"gateway",
			"You are too enchanted by the faerie court to look at the gateway",
			"dream", "You are in a dream", "tree",
			"You are too enchanted by the faerie court to look at a tree", });

		dest_dir = ({ "/players/saber/ryllian/gv3.c", "north", });

	}
}

init()
{
	::init();
	add_action("search", "search");
	add_action("begin", "begin");
	add_action("block", "bte");
	add_action("block", "bt");
	add_action("block", "word");
	add_action("block", "tell");
	add_action("new_say", "say");
	add_action("new_say", "'");
	add_action("new_say", ";");
}

block()
{
	write("You cannot do that here...\n");
	return 1;
}

search()
{
	write("You find nothing\n");
	say(tp + " searches the area\n");
	return 1;
}

begin()
{
	OB = present("instrument", this_player());
	NAME = this_player()->query_real_name();
	if (count < 1) {
		count = count + 1;
		count2 = count2 + 1;
		call_out("intro", 2);
		move_object(clone_object("/players/reflex/guilds/bards/faerie_h.c"),
					environment(ACE));
		return 1;
	}
}

/* <change by="Erasmios" date="2001-05-24> */
ROM(str)
{
	tell_room(environment(ACE), "\nThe Faerie Queen says:\n" + str);
}
/* </change> */

intro()
{
	tell_room(environment(ACE),
			  "\nSmall faeries with bright little wing fly into the glade.\n"
			  +
			  "\nThe faeries fly around you, running their tiny fingers through your hair\n"
			  + "and touching your clothing.\n\n");
	call_out("intro2", 7);
	return 1;
}

intro2()
{
	tell_room(environment(ACE),
			  "\nThe Queen of the Faerie walks gracefully into the glade.\n\n");
	call_out("intro3", 4);
	return 1;
}

intro3()
{
	ROM(" \"Welcome to the Arcadia Gateway " + capitalize(NAME) + ".\n" +
		" We are pleased to once again have a bard within our realm.\"\n");
	tell_room(environment(ACE), "\nThe small faeries giggle.\n\n");
	call_out("intro4", 8);
	return 1;
}

intro4()
{
	ROM(" \"We of the Fay are impressed with your abilities.\n" +
		" For to have traveled to our realm you must be a master of riddles.\"\n");
	call_out("intro5", 5);
	return 1;
}

intro5()
{
	tell_room(environment(ACE),
			  "The Faerie Queen lays down a large tome bound by silver.\n"
			  +
			  "You see that the tome is titled \"There and Back Again\".\n");
	call_out("intro6", 3);
	return 1;
}

intro6()
{
	ROM(" \"I shall propose to you a bargain.\n" +
		" Answer three of my riddles, and I shall teach you the lore of Shaping.\n"
		+ " Fail, and you shall make a gift to me of gold.\"\n");
	call_out("intro7", 5);
	return 1;
}

intro7()
{
	ROM(" \"Do you agree?\"\n");
	return 1;
}

quest1()
{
	ROM(" \"\Alive without breath,\n" +
		" As cold as death,\n" +
		" Never thirsty, ever drinking,\n" +
		" All in mail never clinking.\"\n\n");
	return 1;
}

quest2()
{
	ROM(" \"It cannot be seen, cannot be felt,\n" +
		" Cannot be heard, cannot be smelt,\n" +
		" It lies behind stars and under hills,\n" +
		"   And empty holes it fills.\n" +
		" It comes first and follows after,\n" +
		"   Ends life, kills laughter.\"\n");
	return 1;
}

quest3()
{
	ROM(" \"This thing all things devours:\n" +
		" Birds, beasts, trees, flowers;\n" +
		" Gnaws iron, bites steel;\n" +
		" Grinds hard stones to meal;\n" +
		" Slays kings, ruins town,\n" +
		" And beats high mountain down.\"\n\n");
	return 1;
}

finish()
{
	if (count3 == 3) {
		call_out("finish1", 1);
	} else {
		call_out("oops", 1);
	}
	return 1;
}

finish1()
{
	ROM(" \"\Very good!\"\n\n" +
		" I see that you are a master of riddles.\n" +
		"  We are very amused.\"\n\n");
	tell_room(environment(ACE),
			  "The Faerie Queen teachers you the Art of Shaping.\n\n");
	call_out("teach2", 6);
	return 1;
}

teach2()
{
	object MARK;

	MARK = present("faeries", environment(ACE));
	OB->set_bard_level("8");
	OB->set_bard_xp("64000");
	tell_room(environment(ACE), "You are Bard Level 8!!!\n\n");
	ROM(" \"\Fare thy well, Master of Riddles.\n" +
		" We shall see thee again one day...\"\n");
	move_object(environment(OB),
				"/players/reflex/guilds/bards/bardrooms/lore.c");
	count = 0;
	count2 = 0;
	count3 = 0;
	destruct(MARK);
	return 1;
}

oops()
{
	int TEMP;

	TEMP = 3000;
	ROM(" \"It seems that you were not the riddle master which we took you for.\n" +
		"  It would be best if you were to leave now...\n" +
		"  Perhaps you can try again later.\"\n");
	move_object(environment(OB),
				"/players/reflex/guilds/bards/bardrooms/lore.c");
	environment(OB)->add_money(-TEMP);
	count = 0;
	count2 = 0;
	count3 = 0;
	return 1;
}


new_say(str)
{
	string temp, temp2;

	if (sscanf(str, "%s", temp) == 1) {

		if (temp == "yes" || temp == "yea") {
			if (count2 == 1) {
				correct();
				call_out("quest1", 2);
				call_out("time", 60);
				call_out("quest2", 61);
				return 1;
			}
		}
		if (temp == "fish" || temp == "a fish") {
			if (count2 == 2) {
				correct();
				right();
				remove_call_out("time");
				remove_call_out("quest2");
				call_out("quest2", 2);
				call_out("time", 60);
				call_out("quest3", 61);
				return 1;
			}
		}
		if (temp == "dark" || temp == "the dark") {
			if (count2 == 3) {
				correct();
				right();
				remove_call_out("time");
				remove_call_out("quest3");
				call_out("quest3", 2);
				call_out("time", 60);
				call_out("finish", 62);
				return 1;
			}
		}
		if (temp == "time" || temp == "Time") {
			if (count2 == 4) {
				right();
				remove_call_out("time");
				remove_call_out("finish");
				call_out("finish", 2);
				return 1;
			}
		}

	}
}


time()
{
	ROM(" \"\You must answer a little more quickly...\"\n");
	correct();
}

correct()
{
	count2 = count2 + 1;
}

right()
{
	count3 = count3 + 1;
}

realm()
{
	return "NT";
}
