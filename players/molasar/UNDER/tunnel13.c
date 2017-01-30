

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A fork in the tunnel";
    no_castle_flag = 0;
    long_desc = 
        "The tunnel breaks off into two directions at this point.  A slight draft\n"
        + "comes from the west while your light seems to reflect off something which\n"
        + "lies to the south.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel16", "south",
        "players/molasar/UNDER/tunnel14", "west",
        "players/molasar/UNDER/tunnel12", "north",
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

