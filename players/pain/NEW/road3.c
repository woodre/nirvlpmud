inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A road towards the desert.";
    no_castle_flag = 0;
    long_desc =
        "The road leads northwest towards the Yellow Snake Desert.\n"
        + "Back towards the southeast is the town of Bigelow.\n"
        + "You notice odd tracks along the side of the road.\n";

items = ({
	"road", "A well-travelled road towards the town",
	"tracks", "The tracks appear to be from an armadillo",
});
    dest_dir =
        ({
        "players/pain/NEW/road4", "northwest",
        "players/pain/NEW/square", "southeast",
        });
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

