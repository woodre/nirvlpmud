

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Near the top of a cliff";
    no_castle_flag = 0;
    long_desc = 
        "The path starts to get rocky and difficult to manuever on.  Looking up\n"
        + "you can see you're very close to the top of the cliff.\n";
    dest_dir = 
        ({
        "players/molasar/PLAINS/plain23", "up",
        "players/molasar/SEA/cliff2", "down",
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

