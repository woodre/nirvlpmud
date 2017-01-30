

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Dark room";
    no_castle_flag = 0;
    long_desc = 
        "There are little footprints all over the floor of the tunnel.  You think \n"
        + "you can hear a noise from the room to the east.\n";
    dest_dir = 
        ({
        "/players/deathmonger/UNDERDARK/tunnel7b", "south",
        "/players/deathmonger/UNDERDARK/druegar", "east",
        "/players/deathmonger/UNDERDARK/tunnel5b", "north",
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

