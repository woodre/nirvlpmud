

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
	short_desc = "A trail leading towards the mountains.";
    no_castle_flag = 0;
    long_desc =
        "You are on a trail towards the mountains, north of\n"
        + "the town of Bigelow. To the northwest the mountains rise\n"
        + "out of the trees and to the south you can hear the hustle\n"
        + "and bustle of the people of the small town.\n";

items = ({
	"trail", "A well worn trail towards the mountains",
	"mountains", "The regal peaks of the Black Rock mountains",
});
    dest_dir =
        ({
        "players/pain/NEW/trail3", "north",
	"players/pain/NEW/trail1", "south",
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

