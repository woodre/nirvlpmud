

inherit "/players/blackadder/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Kitchen";
    no_castle_flag = 0;
    long_desc = 
        "This is Blackadders kitchen.  Baldric attempts to cook something edible in\n"
        + "here on a daily basis.  (He is not usually successful, however).\n"
        + "Pots and pans lay strewn about the room.  The stench of garlic is truly\n"
        + "annoying.\n";
    dest_dir = 
        ({
        "/players/blackadder/hall3", "west",
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

