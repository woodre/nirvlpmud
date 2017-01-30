

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Deep inside fortress";
    no_castle_flag = 0;
    long_desc = 
        "You are deep inside the fortress.  You try to look as dead as you can to fit\n"
        + "in with all the ghouls meadering around.  You see a lot of action in the\n"
        + "room to the north.\n";
    dest_dir = 
        ({
        "/players/deathmonger/CASTLE/fortress/entrance", "east",
        "/players/deathmonger/CASTLE/fortress/tavern", "north",
        "/players/deathmonger/CASTLE/fortress/corridor2", "west",
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

