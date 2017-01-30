

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A cobblestone raod";
    no_castle_flag = 0;
    long_desc = 
        "This is an impeccably clean road made of cobblestone.  You are\n"
        + "amazed at the cleanliness of the road, its as if no one has never \n"
        + "walked on it.  The castle shop and armory lies to the west.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/road1", "north",
        "players/molasar/CASTLE/road3", "south",
        "players/molasar/CASTLE/shop", "west",
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

