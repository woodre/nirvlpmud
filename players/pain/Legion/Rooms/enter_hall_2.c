

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A hall through an Evil Fortress";
    no_castle_flag = 0;
    long_desc = 
        "As you continue along the hall you spy yet another painting..\n"
        + "In this one you see poorly dressed soldiers aiming at something...\n"
        + "Perhaps you should look more closely at it... it appears to be very\n"
        + "realistic and dramatic... On the other side of the hall you see\n"
        + "another window looking out over the moat... in this window you\n"
        + "can vaguely make out some horseman... maybe you should see what is going\n"
        + "on out there... it could be important.\n";
    dest_dir = 
        ({
        "players/pain/CASTLE/EVIL/enter_hall_3", "e",
        "players/pain/CASTLE/EVIL/enter_hall_1", "w",
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

