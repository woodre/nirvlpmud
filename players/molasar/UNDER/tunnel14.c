

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A small alcove";
    no_castle_flag = 0;
    long_desc = 
        "What looks like a passage in the tunnel is actually more of an alcove.\n"
        + "The room is almost completely circular and smooth in its structure\n"
        + "except for a small opening to the southwest.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel13", "east",
        "players/molasar/UNDER/tunnel15", "southwest",
        });
}

query_light() {
    return 0;
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

