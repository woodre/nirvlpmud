

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
	short_desc = "A Twisting Path.";
    no_castle_flag = 0;
    long_desc =
          "The trees stand tall above you shielding you from the sun\n"
        + "and providing a surreal setting. To the north you think\n"
        + "that you can make out a cave lying at the edge of the clearing.\n"
        + "To the southeast there is a small clearing in the forest.\n";

items = ({
	"path", "A narrow dirt path running through the forest",
	"cave", "A cave nestled in amoungst the trees to the north",
	"trees", "Tall trees line either side of the path",
});
    dest_dir =
        ({
        "players/pain/NEW/tpath5", "north",
	"players/pain/NEW/tpath3", "southeast",
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

