succor()
{
	object ob;
	string where;
	ob = this_player();
	if (spell(-200, 1, 80, ob) == -1)
	return 0;
	if (REALM != "NT") {
		say("The runes on " + tp + "'s " + TO->query_instrument() +
			" glow a bright silver.\n" + tp +
		" slowly fades from view.\n");

/* Chance for failure */ 
 if(where = (string)call_other("obj/base_tele", "teleport")) {
    write("Your body wavers out of reality.\n");
    write("Something went wrong!\n");
    call_other(this_player(), "add_spell_point", -80);
    TP->move_player("with an astonished look#"+where);
    return 1;
    }

		move_object(ob,
		"/players/reflex/guilds/bards/bardrooms/teleport.c");
		say(tp + " fades into view.\n");
		write("The runes on your instrument glow brightly.\n" +
		"You are now in the Guild hall.\n");
		command("look", this_player());
    	call_other(this_player(), "add_spell_point", -80);
		if (environment(TP)->short("Village church")) {
			write("You arrive in the Bards Guild.\n");
			return 1;
		}
		call_other(this_player(), "add_spell_point", -80);
		return 1;
	}
	write("You cannot Succor from here.\n");
	return 1;
}

bard_who() {

    int number, b;
    string *who, levels;
    object ob;
    object ob2;

    ob = sort_list(users());

    write("\n");
    write(HIM+
        " () - () = () - () = () - () = () - () = () - () = () - () = () - () = () - ()\n"+
        " |                                                                           |\n"+
        " |"+NORM+BOLD+"     Name          Lvl  /  X-Lvl     Gender      Guild         NewGuild    "+
        NORM+HIM+"|\n"+
	" |                                                                           |\n"+NORM);
	for (b = 0; b < sizeof(ob); b += 1) {
		if (ob[b]->query_level() < 21) {
			if(ob[b]->query_invis() && ob[b]->query_level() >= TP->query_level()) continue;
			write(HIM+" |     "+NORM);
			
			write(pad(ob[b]->query_name(), 15));
			write(pad(ob[b]->query_level(), 9));
			write(pad(ob[b]->query_extra_level(), 8));
			write(pad(ob[b]->query_gender(), 13));
			if (ob[b]->query_guild_name() == 0) {
				write("-----         ");
				} else {
				write(pad(ob[b]->query_guild_name(), 14));
			}
			if (present("base_obj", ob[b])) {
				ob2 = present("base_obj", ob[b]);
				write(pad(ob2->query_newguild(), 11));
			}
			if (!present("base_obj", ob[b])) {
				write("           ");
			}
			write(HIM+"|\n"+NORM);
		}
	}
	write
	(HIM+" |                                                                           |\n"
		+
	" () - () = () - () = () - () = () - () = () - () = () - () = () - () = () - ()\n"+NORM);
	write("\n");
	return 1;
}

bard_kin() {

    int b;
    object ob, ob2;

    ob = sort_list(users());

    write(BOLD+"  Name         Bard Lvl     Gender    Title\n"+NORM);
    write(HIM+
        "_________________________________________________________________\n\n"+NORM);

    for (b = 0; b < sizeof(ob); b += 1) {
        if(ob[b]->query_level() > 19 && ob[b]->query_invis()) continue;
	if (present("bard_obj", ob[b])) {
		ob2 = present("bard_obj", ob[b]);
		write("  ");
		if (ob[b]->query_invis() != 0) {
			write(pad("*" + ob[b]->query_name() + "*", 15));
			} else {
			write(pad(ob[b]->query_name(), 15));
		}
		write(pad(ob2->query_bard_level(), 11));
		if (ob2->query_bard_level() > 5) {
			write(" ");
		}
		write(pad(ob[b]->query_gender(), 9));
		write(pad(ob[b]->query_title(), 55));

		write(""+NORM+"\n");
	}
    }
    write(HIM+
        "_________________________________________________________________\n"+NORM);
    return 1;
}

sort_list(str)
{
	int i, j, k;
	object tmp;
	
	j = sizeof(str) - 1;
	for (i = 0; i < j; i++) {
		for (k = 0; k < j; k++) {
			if (str[i]->query_level() < str[i + 1]->query_level()) {
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
			}
		}
	}
	return str;
}

bless(str)
{
	object ob;
	
	if (!str) {
		write("Bless who?\n");
		return 1;
	}
	ob = present(str, environment(TP));
	if (!ob) {
		write("That person is not within sight.\n");
		return;
	}
	if (ob == TP) {
		write("You are already among the ranks of the blessed.\n" +
		"You are a Bard!\n");
		return 1;
	}
	str = capitalize(str);
	if (spell(0, 2, 5, TO) == -1)
	return 0;
	write("You whisper a traditional "+HIG+"Celtic"+NORM+" blessing over " + str + ".\n" +
	str + " is surrounded by a brief "+HIY+"halo"+NORM+" of light.\n");
	say(tp + " whispers a traditional "+HIG+"Celtic"+NORM+" blessing over " + str +
	".\n" + str + " is surrounded by a brief "+HIY+"halo"+NORM+" of light.\n");
	tell_object(ob, "You feel good.\n");
	call_other(TP, "add_spell_point", -5);
	return 1;
}

charm(str)
{
	object ob;
	if (spell(-100, 3, 20, this_object()) == -1)
	return 0;
	ob = first_inventory(environment(TP));
	while (ob) {
		ob->stop_fight();
		ob->stop_fight();
		ob->stop_hunter();
		ob = next_inventory(ob);
	}
	write("You raise your " + TO->query_instrument() +
		" and play a soothing tune.\n" +
	"All of the fighting in the room stops as your music fills the area.\n");
	say(tp + " raises " + TP->query_possessive() + " " +
		TO->query_instrument() + " and plays a soothing tune.\n" +
		"All of the fighting in the room stops as " + tp +
		"'s music fills the area.\n" +
		"You have a strong urge to stop fighting and listen to " + tp +
	".\n");
	call_other(TP, "add_spell_point", -20);
	return 1;
}




bard_image(str)
{
	string target, mess;
	object dest;
	
	if (!str || sscanf(str, "%s %s", target, mess) != 2) {
		write("Who do you want to send a bard image to?\n");
		return 1;
	}
	/* <change by="Erasmios" date="2001-07-05"> */
	if (spell(-100, 4, 1, this_object()) == -1)
	return 0;
	
	dest = find_player(lower_case(target));
	if (!dest || dest->query_invis() > 20) {
		write("That player is not within the realms of magic.\n");
		return 1;
	}
	if (TP->query_level() < 21 && dest->query_tellblock()) {
		write("That person is blocking tells. Please try again later.\n");
		return 1;
	}
	if(TP->query_tellblock() && dest->query_level() < 21 && TP->query_level() < 21) {
		write("You cannot use bising when tellblock is on.\n");
		return 1;
	}
	
	if (in_editor(dest)) {
		write("That wizard is editing and should not be distrubed.\n");
		return 1;
	}
	tell_object(dest,
		"Your ears fill with an light etheral music which somehows suggests that\n"
	+ tp + " " + mess + "\n");
	/* </change> */
	write("You sing your etheral song to " + target +
	", who gets the etheral image of\n" + tp + " " + mess + "\n");
	call_other(TP, "add_spell_point", -1);
	return 1;
}

bards_cant(str)
{
	object ob, ob2;
	
	if (!str) {
		write("What would you like to say?\n");
		return 1;
	}
	ob = first_inventory(environment(TP));
	while (ob) {
		if (living(ob)) {
			if (present("instrument", ob)) {
				tell_object(ob,
				tp + " signs '" + str + "' in bardic cant.\n");
			}
			if (present("medal", ob)) {
				ob2 = present("medal", ob);
				if (ob2->query_cant() == 1) {
					tell_object(ob,
						tp + " signs '" + str +
					"' in bardic cant.\n");
				}
				} else {
				tell_object(ob,
					tp +
				" makes a series of unusual facial and hand gestures.\n");
			}
		}
		ob = next_inventory(ob);
	}
	write("You sign '" + str + "' in bardic cant.\n");
	return 1;
}

int bard_farsinging(string str, int i_emote)
{
	object member, person, *list;
	int i, c;
	string temp;
	
	if (spell(-195, 5, 3) == -1)
	return 0;
	if (!TP->on_channel("gossip")) {
		write("You are not on the gossip channel, so you may not sing.\n");
		return 1;
	}
	if (!str) {
		notify_fail("You must farsing something.\n");
		return 0;
	}
	temp = "(Song) " + tp;
	if (!i_emote)
	temp = "(Songs) " + tp + " sings:";
	temp = temp + " " + str;
	list = users();
	for (i = 0; i < sizeof(list); ++i) {
		person = list[i];
		if (person->on_channel("gossip")) {
			tell_object(person, format(temp));
			++c;
		}
	}
	call_other(TP, "add_spell_point", -3);
	return 1;
}


int bard_farsing(string str)
{
	return bard_farsinging(str, 0);
}

int bard_faremote(string str)
{
	return bard_farsinging(str, 1);
}
