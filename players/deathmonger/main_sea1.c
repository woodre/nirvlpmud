

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Bottom of the ocean";
    no_castle_flag = 0;
    long_desc = 
        "You fool!  You can't swim that far!  As you weaken, you sink deeper and\n"
        + "deeper...\n"
        + "\n"
        + "\n"
        + "\n"
        + "\n"
        + "...and deeper...\n"
        + "\n"
        + "\n"
        + "\n"
        + "\n"
        + "\n"
        + "...and deeper...\n"
        + "\n"
        + "\n"
        + "\n"
        + "\n"
        + "\n"
        + "until you hit the bottom of the sea, where you realize that you can breathe\n"
        + "the water here!\n";
    dest_dir = 
        ({
        "/players/deathmonger/main_sea2", "north",
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

