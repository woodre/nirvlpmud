

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "A tunnel underneath the mountain";
    no_castle_flag = 0;
    long_desc = 
        "A tunnel underneath the mountain.  You can see traces of gold veins\n"
        + "running through the rock wall to the south.  Unfortunatley there is\n"
        + "hardly enough there to waste your time on it.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/tunnel13", "north",
        "players/molasar/UNDER/tunnel17", "east",
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

