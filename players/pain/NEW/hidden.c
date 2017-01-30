

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(100);
    short_desc = "The Lair of the Blood Fisted Clan";
    no_castle_flag = 0;
    long_desc =
        "You are in a hidden room in the lair of the Blood Fisted Clan.\n"
        + "This is the training area of the dark Necromancer, Mortus.\n"
        + "Mortus is the real head of the Blood Fisted Clan and controls\n"
        + "them from this room. Perhaps you should leave before you bother\n"
        + "him and arouse his anger.\n"
	+ "You see that you can exit 'out'.\n";

items = ({
	"walls", "Damp cavern walls covered with calcium residue."+
                 " How cheery",
});
if(!present("mortus"))
move_object(clone_object("/players/pain/NEW/mon/necro.c"),this_object());
if(!present("orc")) {
move_object(clone_object("/players/pain/NEW/mon/orc_m2.c"),this_object());
move_object(clone_object("/players/pain/NEW/mon/orc_m2.c"),this_object());
}

}

init() {
	::init();
add_action("out","out");
add_action("confuse","confuse");
}

realm() { return "NT"; }
out() {
if(present("mortus")) {
	write("Mortus will not allow you to leave.\n");
	return 1;
}
this_player()->move_player("out to the throne room#/players/pain/NEW/throne");
return 1;
}

confuse() {
write("You dare attempt to confuse Mortus??\n");
this_player()->hit_player(20);
return 1;
}
query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
/*
room_is_modified() {
    return 1;
}
*/

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

