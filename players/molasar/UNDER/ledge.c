

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A ledge on the mountain";
    no_castle_flag = 0;
    long_desc = 
        "You are on a very small ledge.  Looking down you can see that you are\n"
        + "not far from the foot of the mountain.  \n";
    dest_dir = 
        ({
        "players/molasar/UNDER/steep2", "west",
        "players/molasar/UNDER/foot2", "down",
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

