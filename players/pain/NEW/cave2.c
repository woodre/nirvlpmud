

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Inside a Dark Cave";
    no_castle_flag = 0;
    long_desc =
	  "As you stand in the cave the darkness presses down on you\n"
	+ "filling you with a sense of profound dread. The cave is large\n"
	+ "and drafty, and at first glance looks deserted. You see foot\n"
	+ "prints leading further into the cave. You begin to wonder if\n"
	+ "now might be a good time to turn back.\n";
items = ({
	"foot prints", "Huge footprints leading further into the cave",
});
    dest_dir =
        ({
        "players/pain/NEW/cave3", "in",
        "players/pain/NEW/cave1", "out",
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

