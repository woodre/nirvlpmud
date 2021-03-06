

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "mid_volcano";
    no_castle_flag = 0;
    long_desc = 
        "                     WARNING:  THIS IS THE MOST POWERFUL\n"
        + "                     MONSTER ON THE MUD.  GO BACK THE WAY\n"
        + "                     YOU CAME IF YOU ARE NOT SURE YOU ARE\n"
        + "                     VERY POWERFUL YOURSELF.  IF YOU THINK\n"
        + "                     YOU ARE READY, THEN PROCEED DOWN THE \n"
        + "                     CRATER, THUS WARNED...\n";
    dest_dir = 
        ({
        "/players/deathmonger/volcano", "up",
        "/players/deathmonger/CASTLE/tarrasque1", "down",
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

