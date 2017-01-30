

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "west hall2";
    no_castle_flag = 0;
    long_desc = 
        "A grand hall.  The Arnold Schwartzeneggar Theme Park is to the west.\n"
        + "               The Way-Back Machine is to the north.\n"
        + "               The Yellow Brick Road begins to the south.\n";
    dest_dir = 
        ({
        "/players/deathmonger/west_hall1", "east",
        "/players/deathmonger/CASTLE/oz/munchkin", "south",
        "/players/deathmonger/CASTLE/peabody", "north",
        "/players/deathmonger/CASTLE/arnold/conan", "west",
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

