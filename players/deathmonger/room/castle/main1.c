

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a marshy swampland.  The tree growth is so thick that you c  \n"
        + "can't see the sky (thus it is always night in the swamp).  You see a crocodile\n"
        + "cruising the waters looking for his next meal with his glowing eyes.  A water\n"
        + "snake slithers by.  Watch your step as you wade through the swamp!\n";
    dest_dir = 
        ({
        "/players/deathmonger/island_shore", "south",
        "/players/deathmonger/main2", "north",
        });
}

query_light() {
    return 0;
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

