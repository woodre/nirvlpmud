

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "There is a stream here running east to west.  You can see a school of fish\n"
        + "in the water.  A monkey drops a coconut on your head and you make monkey\n"
        + "stew out of him for dinner.  Don't let the mosquitos bite or you'll get\n"
        + "malaria.\n";
    dest_dir = 
        ({
        "/players/deathmonger/main4", "south",
        "/players/deathmonger/main6", "north",
        "/players/deathmonger/CASTLE/coatl", "east",
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

