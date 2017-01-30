

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A great forest";
    no_castle_flag = 0;
    long_desc = 
        "You are near the center of a great forest.  Huge trees loom above you\n"
        + "blocking out the majority of the sunlight.  Paths lead off in all\n"
        + "directions.\n";
    dest_dir = 
        ({
        "players/molasar/FOREST/forest5", "north",
        "players/molasar/FOREST/forest3", "south",
        "players/molasar/FOREST/forest14", "east",
        "players/molasar/FOREST/forest1", "west",
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

