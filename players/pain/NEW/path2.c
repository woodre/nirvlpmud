

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
	short_desc = "A path leading through the forest.";
    no_castle_flag = 0;
    long_desc =
        "You are just northeast of where the path splits.\n"
        + "The trees stand tall above you shielding you from the sun\n"
        + "and providing a surreal setting. To the far north you think\n"
        + "that you can make out some sort of building in the clearing.\n"
        + "To the southwest there is a meeting of two paths.\n";

items = ({
	"path", "A narrow dirt path running through the forest",
	"trees", "Tall trees line either side of the path",
});
    dest_dir =
        ({
        "players/pain/NEW/path3", "north",
	"players/pain/NEW/path1", "southwest",
        });
if(!present("footman"))
{
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

