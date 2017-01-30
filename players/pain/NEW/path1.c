

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A split in the path";
    no_castle_flag = 0;
    long_desc =
        "The path towards the mountains splits here, with one branch\n"
        + "heading to the mountains to the northwest, another heading\n"
        + "into the forest to the northeast, a path leading towards a\n"
	+ "valley to the north, and the fourth heading back to the\n"
        + "town of Bigelow to the south. You think you can make out\n"
        + "the shape of a building to the northeast.\n"
	     + "You see a sign staked into the ground here.\n";

items = ({
	"path", "A narrow, muddy path through the forest",
	"sign", "The sign reads:\n"+
                "\nAdventurer's are no longer welcome to explore the valley.\n"+
        "It is too dangerous and unstable.\n"+
                "By order of the Mayor of Bigelow, 1-29-1997",

});
    dest_dir =
        ({
        "players/pain/NEW/path2", "northeast",
        "players/pain/NEW/tpath1", "northwest",
        "players/pain/NEW/trail3", "south",
        });
if(!present("worker"))
{
move_object(clone_object("/players/pain/NEW/mon/worker"),this_object());
move_object(clone_object("/players/pain/NEW/mon/worker"),this_object());
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

