

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Foot of the mountain";
    no_castle_flag = 0;
    long_desc = 
        "You have reached the foot of a large mountain.  There is a somewhat\n"
        + "rocky path that leads up the side of the mountain.\n";
    dest_dir = 
        ({
        "players/molasar/UNDER/climb1", "up",
        "players/molasar/UNDER/path3", "south",
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

