

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A trail towards the mountains.";
    no_castle_flag = 0;
    long_desc =
        "The path towards the mountains splits to the north of here.\n"
        + "You can hear animal noises all around you and you wonder if\n"
        + "you might be able to catch a glimpse of something on your journey.\n"
        + "The town lies to the south of here and the mountains tower over\n"
        + "the forest to the north.\n";

items = ({
	"trail", "A narrow, dirt trail towards the mountains",
});
    dest_dir =
        ({
        "players/pain/NEW/path1", "north",
        "players/pain/NEW/trail2", "south",
        });
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

