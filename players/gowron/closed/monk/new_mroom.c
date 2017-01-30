inherit "room/room";

reset(arg) {
	if (arg)
           return;
	set_light(1);
	short_desc = "The monks room";
	long_desc = "Monk room, blah, blah, blah, will do later.\n";
}

init() {
	if (!present("new_mrobe", this_player())) {
           tell_object(this_player(), "You are repelled by a shield.\n");
	   say(this_player()->query_name()+" tried to break in!\n");
	   this_player()->move_player("away#room/church");
	}
}

