

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Foot of the mountain";
    no_castle_flag = 0;
    long_desc = 
        "You are standing at the foot of the northern side of a huge mountain.\n"
        + "A large plain extends out in from of you in all directions.\n"
        + "A lush green forest lies far to the northeast and you can see a castle\n"
        + "in the distance of to the northwest.\n";
    dest_dir = 
        ({
        "players/molasar/PLAINS/plain1", "north",
        "players/molasar/PLAINS/plain3", "east",
        "players/molasar/PLAINS/plain2", "west",
        "players/molasar/UNDER/ledge", "up",
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

