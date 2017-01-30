inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A road towards the desert.";
    no_castle_flag = 0;
    long_desc =
        "The road leads northwest towards the Yellow Snake desert and\n"
        + "back towards Bigelow's town square to the southeast.\n";

items = ({
	"road", "A well-travelled road towards the town",
});
    dest_dir =
        ({
        "players/pain/NEW/road5", "northwest",
        "players/pain/NEW/road3", "southeast",
        });
if(!present("merchant"))
move_object(clone_object("/players/pain/NEW/mon/merchant"),this_object());
if(!present("footman"))
{
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
move_object(clone_object("/players/pain/NEW/mon/footman"),this_object());
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

