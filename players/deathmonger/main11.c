

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Fortress";
    no_castle_flag = 0;
    long_desc = 
        "You come upon a huge fortress that appears to be dead.  Its massive walls\n"
        + "suggest that it could hold off huge armies.  The drawbridge is down and\n"
        + "seems to almost invite you to come in...\n"
        + "You can enter or go on to the north.\n";
    dest_dir = 
        ({
        "/players/deathmonger/main10", "south",
        "/players/deathmonger/CASTLE/fortress/entrance", "enter",
        "/players/deathmonger/main12", "north",
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

