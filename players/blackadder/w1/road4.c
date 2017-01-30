

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "End of the road";
    no_castle_flag = 0;
    long_desc = 
        "This is the end of the road for now.  In the distance you see a raging battle\n"
        + "around an ancient castle.  Stay tuned for further developments.\n";
    dest_dir = 
        ({
        "/players/blackadder/w1/bridge", "south",
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

