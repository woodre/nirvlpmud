

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "You find an arctic plateau at the top of the mountain.  Straight across\n"
        + "the plateau is the volcano.  Unfortunately, it very cold and the wind\n"
        + "bites at your nose.  It's DAMN COLD UP HERE!\n";
    dest_dir = 
        ({
        "/players/deathmonger/main15", "down",
        "/players/deathmonger/main17", "north",
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

