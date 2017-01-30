inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Just South of the Desert.";
    no_castle_flag = 0;
    long_desc =
        "The road leads north into the Yellow Snake Desert and back\n"
        + "southeast towards the town of Bigelow. The heat of the desert\n"
        + "washes over you, making you want to turn back.\n"
	     + "A small sign is staked into the ground here.\n";

items = ({
	"road", "A well-travelled road towards the town",
	"sign", "The sign reads:\n"+
		"\nAdventurer's are no longer welcome to explore the desert.\n"+
	"It is too dangerous and unstable.\n"+
		"By order of the Mayor of Bigelow, 1-29-1997",
});
    dest_dir =
        ({
        "players/pain/NEW/road4", "southeast",
        });
if(!present("paladin"))
move_object(clone_object("/players/pain/NEW/mon/pal"),this_object());
if(!present("footman"))
{
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
}
if(!present("guard"))
{
move_object(clone_object("/players/pain/NEW/mon/t_guard"),this_object());
move_object(clone_object("/players/pain/NEW/mon/t_guard"),this_object());
}
}

init() {
	::init();
}

realm() { return "NT"; }


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

