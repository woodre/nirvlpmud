

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Garden";
    no_castle_flag = 0;
    long_desc = 
        "The amount of flora found in the garden amazes you.  From the most exotic\n"
        + "to the simplest weed have been placed here.  This garden presents a unique\n"
        + "chance for a person to see every type of plant in existence.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/garden4", "south",
        "players/molasar/CASTLE/garden2", "east",
        "players/molasar/CASTLE/garden1", "southeast",
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

