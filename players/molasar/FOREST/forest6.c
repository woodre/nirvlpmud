

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A great forest";
    no_castle_flag = 0;
    long_desc = 
        "You are at the western edge of a great forest.\n";
    dest_dir = 
        ({
        "players/molasar/FOREST/forest7", "north",
        "players/molasar/FOREST/forest5", "east",
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

