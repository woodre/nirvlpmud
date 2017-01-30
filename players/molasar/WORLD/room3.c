

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "In a mist";
    no_castle_flag = 0;
    long_desc = 
        "The mist is sparse in this area allowing you to go in any direction.\n";
    dest_dir = 
        ({
        "players/molasar/WORLD/room3", "north",
        "players/molasar/WORLD/room2", "south",
        "players/molasar/WORLD/hollow", "east",
        "players/molasar/WORLD/room4", "west",
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

