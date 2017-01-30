

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Near the bottom of a cliff";
    no_castle_flag = 0;
    long_desc = 
        "You are very close to the bottom of a large cliff.  Looking east you\n"
        + "can see a vast sea and just barely make out the outline of a \n"
        + "small isle.  A trail runs up and down the cliff.\n";
    dest_dir = 
        ({
        "players/molasar/SEA/cliff1", "up",
        "players/molasar/SEA/beach", "down",
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

