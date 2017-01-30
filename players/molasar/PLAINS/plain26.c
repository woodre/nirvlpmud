

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A large open plain";
    no_castle_flag = 0;
    long_desc = 
/* changed castle entry to plain11   Eurale 4/7/97
        "You are in a large open plain.  Paths lead north, south, and east.\n"
        + "To the west you can see a large castle.\n";
*/
  "You are in a large open plain.  Paths lead north, south, and east.\n";
    dest_dir = 
        ({
        "players/molasar/PLAINS/plain27", "north",
        "players/molasar/PLAINS/plain25", "south",
        "players/molasar/PLAINS/plain20", "east",
/*
        "players/molasar/CASTLE/entry", "west",
*/
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

