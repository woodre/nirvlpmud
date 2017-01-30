

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "In a mist";
    no_castle_flag = 0;
    long_desc = 
        "The mist begins to gather together forming a path, or rather forcing you\n"
        + "to go in one direction.  Every now and then you can see a dark figure\n"
        + "dart across your path.\n";
    dest_dir = 
        ({
        "players/molasar/WORLD/room4", "north",
        "players/molasar/WORLD/room6", "south",
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

