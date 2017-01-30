teach_pal(str)
{
	string who, sponsor;
	int level, level2;
	object ob, OB;

	if (spell(-200, 6, 0) == -1)
		return 0;

	if (!str || sscanf(str, "%s", who) != 1) {
		write
			("To teach a Palidan Bardic Cant, type: teach <palidan name>\n");
		return 1;
	}

	if (!present(who, environment(TP))) {
		write(CAP + " is not close enough to teach.\n");
		return 1;
	}

	ob = find_player(who);
	sponsor = find_player(who)->query_real_name();

	if (ob->query_guild_name() == "paladin") {
		OB = present("medal", ob);
		OB->set_cant("1");

		write("You have taught " + CAP + " the secrets of Bardic Cant.\n");
		tell_object(ob, tp + " teaches you the secrets of Bardic Cant.\n" +
					"To use, type: cant <message>\n" +
					"Another skill brought to you by the Bardic Guild of Ryllian.\n");
		return 1;
	}
}
