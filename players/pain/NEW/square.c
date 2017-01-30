inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The Town Square";
    no_castle_flag = 0;
    long_desc =
        "The Town Square is surrounded by a number of different shops.\n"
        + "To the north is the main shop, where you can sell and buy\n"
        + "a variety of items. To the west is a heal shop and to the east\n"
        + "is an armor shop. Perhaps you should check these out.\n"
	+ "To the northwest is a road leading out of the town.\n"
	+ "To the northeast a trail leads into the mountains.\n"
        + "To the southwest is an odd looking glowing building.\n";

items = ({
	"building", "A strange looking building with a glow about it",
});
    dest_dir =
        ({
	"players/pain/NEW/trail1", "northeast",
        "players/pain/NEW/shop", "north",
	"players/pain/NEW/road3", "northwest",
        "players/pain/NEW/hshop", "west",
/*
        "players/pain/NEW/mshop", "southwest",
*/
	"players/pain/NEW/ashop", "east",
	"players/pain/NEW/road2", "south",
        });
if(!present("paladin"))
{
move_object(clone_object("/players/pain/NEW/mon/pal"),this_object());
move_object(clone_object("/players/pain/NEW/mon/pal"),this_object());
}
if(!present("worker"))
{
move_object(clone_object("/players/pain/NEW/mon/worker"),this_object());
move_object(clone_object("/players/pain/NEW/mon/worker"),this_object());
}
if(!present("guard"))
move_object(clone_object("/players/pain/NEW/mon/t_guard"),this_object());
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

