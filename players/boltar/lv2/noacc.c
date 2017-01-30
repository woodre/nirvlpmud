    room = find_object("players/boltar/lv2/pawnstorage.c");
    play_name = call_other(this_player(),"query_name",0);
    if (!present("box",room)) {
        write("You you don't have an account.\n");
	return 1;
	}
