

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A Stone Entrance to an Ancient Monastary";
    no_castle_flag = 0;
    long_desc = 
        "The roadway ends at a large granite archway that is the\n"
        + "entrance to a very old looking\n"
        + "monastary. The granite is wet as is most of the\n"
        + "lush surroundings. Covering the archway is\n"
        + "a carved inscription.\n"
        + "You hear chanting from deep within the stone\n"
        + "building beckoning you deeper.\n";
    dest_dir = 
        ({
        "closed/guild/monastary/rm1.c", "north",
        "/room/crop.c", "out",
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

