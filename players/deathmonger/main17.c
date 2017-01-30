

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "main road";
    no_castle_flag = 0;
    long_desc = 
        "The plateau seems endless.  A blizzard lashes you with ice daggers.  You can still see the \n";
    dest_dir = 
        ({
        "/players/deathmonger/main16", "south",
        "/players/deathmonger/volcano", "up",
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

