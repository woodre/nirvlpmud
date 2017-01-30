

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "There are leaves all over the ground.  The forest suddenly grows colder and\n"
        + "darker.  You feel like a thousand pairs of eyes are watching you.  You catch\n"
        + "a glimpse of something moving in the brush.\n";
    dest_dir = 
        ({
        "/players/deathmonger/main7", "south",
        "/players/deathmonger/main9", "north",
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

