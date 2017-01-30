

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "In a mist";
    no_castle_flag = 0;
    long_desc = 
        "The mist seems to form some sort of path for you to follow.  Behind the mist\n"
        + "you can see many shapes moving around.  The seem to be watching you\n"
        + "closely.\n";
    dest_dir = 
        ({
        "players/molasar/WORLD/room5", "north",
        "players/molasar/WORLD/room7", "east",
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

