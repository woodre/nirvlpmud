

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "tunnel1";
    no_castle_flag = 0;
    long_desc = 
        "You enter a dark system of tunnels.  You can hear echoes of screams far \n"
        + "away.  A sign etched into the ceiling of the cavern reads:\n"
        + "                      WELCOME TO THE UNDERDARK\n"
        + "     All kinds of cavern-dwelling creatures live here, so watch your step!\n";
    dest_dir = 
        ({
        "/players/deathmonger/UNDERDARK/tunnel2", "south",
        "/players/deathmonger/CASTLE/tarrasque1", "north",
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

