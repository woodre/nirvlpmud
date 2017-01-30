

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A bridge";
    no_castle_flag = 0;
    long_desc = 
        "This is a wooden bridge which spans the Slag river.  You are quite relieved\n"
        + "that you didn't need to swim through the dirty brown muck down below.  The \n"
        + "road continues to the north.\n";
    dest_dir = 
        ({
        "/players/blackadder/w1/road4", "north",
        "/players/blackadder/w1/road3", "south",
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

