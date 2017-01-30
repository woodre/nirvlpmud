inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A road towards a small town.";
    no_castle_flag = 0;
    long_desc =
        "The road leads north towards the town's square and out\n"
        + "back towards the continent's main road.\n";

items = ({
  "road", "A well-travelled road that cuts through the continent of Hirandea",
});
    dest_dir =
        ({
        "players/pain/NEW/road2", "north",
        "room/vill_shore2", "out",
        "players/maledicta/cont/rooms/498.c", "continent",
        });
if(!present("merchant"))
move_object(clone_object("/players/pain/NEW/mon/merchant"),this_object());
if(!present("bunny"))
{
move_object(clone_object("/players/pain/NEW/mon/bunny"),this_object());
move_object(clone_object("/players/pain/NEW/mon/bunny"),this_object());
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

