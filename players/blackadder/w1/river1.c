

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "riverbank";
    no_castle_flag = 0;
    long_desc = 
        "You are standing on the bank of the Slag river.  Dirty brown water filled\n"
        + "with sludge flows slowly to the south.  You think about attempting to cross\n"
        + "the river here, then you think better of it.  Your passage is blocked to\n"
        + "the north and south.  There is a road off to the east.\n";
    dest_dir = 
        ({
        "/players/blackadder/w1/road1", "east",
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

