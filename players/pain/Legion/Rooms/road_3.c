

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A Road to and Evil Fortress";
    no_castle_flag = 0;
    long_desc = 
        "You are standing right before the Fortress\n"
        + "Fear runs up and down your spine as the drawbridge begins to lower\n"
        + "You begin to contemplate your flight from this place\n"
        + "You know that your chances of living are nill\n"
        + "Good luck... godspeed\n";
    dest_dir = 
        ({
        "players/pain/CASTLE/EVIL/Entrance", "drawbridge",
        "players/pain/CASTLE/EVIL/road_2", "s",
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

