

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Upper platform";
    no_castle_flag = 0;
    long_desc = 
        "This is the entry platform for the second level of the city.\n"
        + "A rope ladder leads down to the lower level while a regal walkway decorated\n"
        + "with numerous banners leads northeast.\n";
    dest_dir = 
        ({
        "players/molasar/FOREST/UPPER/plat11", "northeast",
        "players/molasar/FOREST/UPPER/plat3", "down",
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

