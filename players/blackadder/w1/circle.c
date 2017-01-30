

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

move_object(clone_object("/players/blackadder/w1/tapestry"),this_object());
    set_light(1);
    short_desc = "A circle of stones";
    no_castle_flag = 0;
    long_desc = 
        "You have arrived at a group of large stones arranged in a roughly circular\n"
        + "pattern.  Several of the stones have been toppled and it appears that the\n"
        + "place has not been maintained for many years.  A large stone altar stands\n"
        + "in the center of the circle.\n";
    dest_dir = 
        ({
        "/players/blackadder/w1/road1", "north",
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

