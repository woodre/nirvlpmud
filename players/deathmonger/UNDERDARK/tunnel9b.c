

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Dark room";
    no_castle_flag = 0;
    long_desc = 
        "You are in a long dark corridor.  The fungal growth grows heavy.\n"
        + "You can see signs of life to the east.\n";
    dest_dir = 
        ({
        "/players/deathmonger/UNDERDARK/tunnel8b", "north",
        "/players/deathmonger/UNDERDARK/mycon/entrance", "east",
        "/players/deathmonger/UNDERDARK/tunnel10", "west",
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

