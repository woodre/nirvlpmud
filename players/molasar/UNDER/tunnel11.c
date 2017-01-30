

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A tunnel underneath the mountain";
    no_castle_flag = 0;
    long_desc = 
        "A tunnel underneath the mountain.  There is a small hole in the floor\n"
        + "with crude steps carved into the side of the wall leading down.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel10", "west",
        "players/molasar/UNDER/tunnel12", "down",
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

