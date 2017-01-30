
inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A garden";
    no_castle_flag = 0;
    long_desc = 
        "Many flowers and exotic plants decorate the paths of the garden.\n"
        + "The different aromas and colors overload your senses, making you feel\n"
        + "giddy.  To the north you see a large oak tree while a well can be seen\n"
        + "to the west.\n";
    dest_dir = 
        ({
        "players/molasar/CASTLE/garden2", "north",
        "players/molasar/CASTLE/entrance", "south",
        "players/molasar/CASTLE/garden4", "west",
        "players/molasar/CASTLE/garden3", "northwest",
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

