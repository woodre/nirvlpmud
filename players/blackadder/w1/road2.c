

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A north/south road";
    no_castle_flag = 0;
    long_desc = 
        "The road continues to the north.  It has not been well cared for over the\n"
        + "years.  In between the cracked surface many weeds have taken root.\n";
    dest_dir = 
        ({
        "/players/blackadder/w1/road1", "south",
        "/players/blackadder/w1/road3", "north",
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

