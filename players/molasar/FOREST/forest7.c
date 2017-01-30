

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A great forest";
    no_castle_flag = 0;
    long_desc = 
"You are at the western edge of a great forest.  A small clearing is west.\n";
    dest_dir = 
        ({
        "players/molasar/FOREST/forest6", "south",
        "players/molasar/FOREST/forest8", "east",
	"players/molasar/FOREST/Eforest7","west",
        });
}

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

