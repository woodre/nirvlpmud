

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Gateworld";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a dark and forboding world.  There is very little light,\n"
        + "just enough for you to see.  There is a transparency about all the\n"
        + "objects around you, as if you could walk right through them.  A faint\n"
        + "mist swirls around you almost urging you to go north.\n";
    dest_dir = 
        ({
        "players/molasar/WORLD/room2", "north",
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

