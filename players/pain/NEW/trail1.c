

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
	short_desc = "Northeast of Bigelow's Square.";
    no_castle_flag = 0;
    long_desc =
        "You are just northeast of the town square of Bigelow.\n"
        + "To the north lies the Black Rock Mountains and adventure.\n"
        + "The forest around you is still and quiet, disrupted only by\n"
        + "a few bunnies hopping here and there.\n";

items = ({
	"trail", "A narrow trail leading towards the mountains",
});
    dest_dir =
        ({
        "players/pain/NEW/trail2", "north",
	"players/pain/NEW/square", "southwest",
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

