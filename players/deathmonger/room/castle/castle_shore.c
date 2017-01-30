

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The shore near the castle.";
    no_castle_flag = 0;
    long_desc = 
        "You are on the shore of a great sea.  Far off you can see a volcanic island,\n"
        + "with a haze of smoke surrounding the crater.  The island itself appears to\n"
        + "be geographically varied, with jungles and deserts and everything in between.\n"
        + "It's a long way off, but you can probably swim to it.\n"
        + "\n"
        + "NOTE:  The island is a very dangerous area--don't go there unless you're \n"
        + "       fairly powerful.\n";
    dest_dir = 
        ({
        "/players/deathmonger/hall3", "south",
        "/players/deathmonger/main_sea1", "swim",
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

