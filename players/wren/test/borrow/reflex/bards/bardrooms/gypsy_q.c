#define ACE find_living("group")
#define tp this_player()->query_name()
/* <change by="Erasmios" date="2001-05-24> */
/*#define ROM tell_room(environment(ACE), "\nCrystal says:\n*/
/* </change> */
string NAME, SIB;
object OB;

inherit "room/room";

int t, count, count2, count3;

reset(int arg)
{
	if (!present("children")) {
		move_object(clone_object("/players/saber/monsters/gypsy_kids.c"),
					this_object());
	}
	if (!present("group")) {
		move_object(clone_object("/players/saber/monsters/gypsy_p.c"),
					this_object());
	}
	if (!arg) {
		set_light(1);
		short_desc = "Gypsy Camp";
		long_desc =
			"You stand in the midst of a gypsy camp.  The camp is encircled by a small ring\n"
			+
			"of brightly colored wagons and a few vividly chromatic tents.  All about you\n"
			+
			"are dark skinned men, women and children with dark features and black hair,\n"
			+
			"dressed in multicolored gypsy cloth.  In the center of the camp is a single\n"
			+ "wagon decorated with silver runes and symbols.\n";

		items = ({
			"camp", "You stand in the midst of a gypsy camp",
			"ring",
			"The camp is encircled by a small ring of brightly colored wagons",
			"men", "There are many dark skinned gypsy men here", "women",
			"There are many dark skinned gypsy women here", "children",
			"There are many dark skinned gypsy children here", "wagons",
			"There are 7 brightly colored wagons here", "tents",
			"There are a few tents in the camp sight", "wagon",
			"There is a single wagon decorated with silver runes and symbols here", });

		dest_dir = ({ "/players/saber/ryllian/gv3.c", "north", });

	}
}

init()
{
	::init();
	add_action("search", "search");
	add_action("begin", "begin");
	add_action("spc_charm", "charm");
	add_action("block", "bte");
	add_action("block", "bt");
	add_action("block", "alt");
	add_action("block", "ale");
	add_action("block", "succor");
	add_action("block", "goportal");
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
	SIB = "sister";
	if (this_player()->query_gender() == "male") {
		SIB = "brother";
	}
	if (count < 1) {
		count = count + 1;
		call_out("intro", 3);
		return 1;
	}
}

/* <change by="Erasmios" date="2001-05-24> */
ROM(str)
{
	tell_room(environment(ACE), "\nCrystal says:\n" + str);
}

/* </change> */

intro()
{
	ROM(" \"Welcome to our camp " + capitalize(NAME) + ".\n" +
		"  I am Crystal, gypsy mistress of the mystic arts.\n" +
		"  We of the gypsy kin welcome you who claim to be our " + SIB +
		".\n");
	call_out("intro2", 9);
	return 1;
}

intro2()
{
	ROM(" \"We hope that you will accept our hospitality.\"\n" +
		"\nCrystal walks forward and places a kiss upon your left cheek.\n\n");
	call_out("intro3", 6);
	return 1;
}

intro3()
{
	ROM(" \"But know this, " + SIB + ", that while we of the kin\n" +
		"  are family, first and foremost we are indivuduals.\n" +
		"  It is this individuality which gives us our strength\n" +
		"  and power to cope with adversity.\"\n");
	call_out("intro4", 9);
	return 1;
}

intro4()
{
	ROM(" \"Now, by whose authority do you come here to learn from us?\"\n");
	return 1;
}

begin1()
{
	ROM(" \"So you are an individual than?  This is good.\n" +
		"  But a gypsy is known for their wits as much as for\n" +
		"  their individuality.  Can you think quickly upon your feet?\"\n");
	call_out("begin2", 7);
	return 1;
}

begin2()
{
	ROM(" \"Look!\"\n" +
		"Crystal points across the clearing.\n" +
		"\nA massive Troll bursts through a wagon into the clearing!\n\n");
	move_object("/players/saber/monsters/gypsy_troll.c",
				"/players/reflex/guilds/bards/bardrooms/gypsy_q.c");
	call_out("begin3", 6);
	return 1;
}

begin3()
{
	ROM(" \"What will you do " + NAME + "?\n" +
		"  Save us, O heroic Bard!\"\n" +
		"\nYou think you see Crystal smile faintly.\n" +
		"\nThe troll charges towards the group of children.\n\n");
	call_out("begin4", 5);
	return 1;
}

begin4()
{
	ROM(" \"Quickly, calm the troll down!  Save our children!\"\n");
	return 1;
}

mid1()
{
	ROM(" \"Very good.\"\n" +
		"\nThe illusion of the troll fades.\nThe gypsy children stand up and smile at you.\n");
	call_out("mid2", 6);
	return 1;
}

mid2()
{
	ROM(" \"Now, answer for me this question.\n" +
		"  Where is the silversword?\"\n");
	return 1;
}

fin1()
{
	ROM(" \"Very good " + capitalize(NAME) + ".\n" +
		"  We accept you as gypsy kin.  Would you like to learn our lore?\"\n");
	return 1;
}

teach1()
{
	ROM(" \"Very good!\"\n\n" +
		"Crystal teaches you the Psalm of the Chromatic Spheres.\n" +
		"\nCrystal teaches you the Ayre of Ability.\n\n");
	tell_room(environment(ACE),
			  "Crystal teaches you the Song of Second Sight.\n\n" +
			  "Crystal teaches you the Farsong.\n\n" +
			  "Crystal teaches you a gypsy curse.\n\n");
	call_out("teach2", 10);
	return 1;
}

teach2()
{
	OB->set_bard_level("5");
	OB->set_bard_xp("16000");
	ROM(" \"\Fare thee well, kin of our blood.\"\n" +
		"\nCrystal hugs you and gives you a medallion.\n\n");
      move_object(clone_object("/players/saber/closed/new_mini/gypsy.c"),
				environment(OB));
	return 1;
}


new_say(str)
{
	string temp, temp2;

	if (sscanf(str, "%s", temp) == 1) {

		if (temp == "my own" || temp == "mine" || temp == "myself"
			|| temp == "none" || temp == "nobody" || temp == "nobodies") {
			if (count2 == 0) {
				correct();
				call_out("begin1", 2);
				return 1;
			}
		}
		if (temp == "circle" || temp == "Circle") {
			if (count2 == 2) {
				correct();
				call_out("fin1", 2);
				return 1;
			}
		}
		if (temp == "yes" || temp == "yea") {
			if (count2 == 3) {
				correct();
				call_out("teach1", 2);
				return 1;
			}
		}

	}
}


spc_charm()
{
	object DUMP;

	DUMP = present("troll", environment(find_player(NAME)));
	destruct(DUMP);
	correct();
	call_out("mid1", 1);
}

correct()
{
	count2 = count2 + 1;
}

realm()
{
	return "NT";
}
