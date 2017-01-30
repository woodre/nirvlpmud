inherit "room/room";

void
reset(int arg) {
    if (arg) return;

    set_no_clean(1);
    short_desc = ("The wastelands");
    long_desc = (
"The land here is ruined.  There doesn't seem to be anyone around\n" +
"that you can see.  The ground feels like glass, although in some\n" +
"places it looks as if life has started to form again.  Ahead of\n" +
"you is the grave of a forest of long ago.\n" +
"\tThe only obvious exits are north and south.\n");
    set_light(1);
}

void
long(string str) {
    if (set_light(0) <= 0)
	::long();
    else
	write(long_desc);
}

init() {
    ::init();
    add_action("move", "north");
    add_action("move", "south");
    this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->clear_fight_area();
}

move() {
    string oppn;
    object opp;

    if (opp = (object) this_player()->query_attack()) {
	oppn = opp->query_name();
	this_player()->set_title("ran from a fight with " + oppn);
    }
    this_player()->clear_fight_area();
    if (query_verb() == "north")
	this_player()->move_player("north#/players/dragnar/WasteLands/rooms/room2");
    else if (query_verb() == "south")
	this_player()->move_player("south#/players/dragnar/WasteLands/rooms/entrance");
    return 1;
}
