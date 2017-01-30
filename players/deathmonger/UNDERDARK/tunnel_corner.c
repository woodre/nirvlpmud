

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Underdark tunnel";
    no_castle_flag = 0;
    long_desc = 
        "You come to a sort of turn in the tunnel to the west.  Much traffic appears\n"
        + "to have passed through here, and strange footprints cover the floor.\n";
    dest_dir = 
        ({
        "/players/deathmonger/UNDERDARK/tunnel9a", "north",
        "/players/deathmonger/UNDERDARK/tunnel10", "east",
        "/players/deathmonger/UNDERDARK/tunnel11", "west",
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

