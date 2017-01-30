

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "hall1";
    no_castle_flag = 0;
    long_desc = 
        "We got stuff here!  Really!...Well, eventually...*sigh*\n";
    dest_dir = 
        ({
        "/players/deathmonger/entrance", "south",
        "/players/deathmonger/east_hall1", "east",
        "/players/deathmonger/west_hall1", "west",
        "/players/deathmonger/hall2", "north",
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

