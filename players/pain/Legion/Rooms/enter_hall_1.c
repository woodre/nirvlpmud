

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A hall in an Evil Fortress";
    no_castle_flag = 0;
    long_desc = 
        "You are travelling down the hallway to an unknown destination.\n"
        + "Around you, you can sense the prensence of Evil... pure Evil.\n"
        + "As you look around the hallway you see a window looking out over the moat\n"
        + "towards the battle raging on outside the Castle... you desire to look\n"
        + "more closely. On the other side of the hall you see a painting of what\n"
        + "appears to be a World War II battle... you should look at it more closely\n"
        + "to discover more about it... it may give you a clue as to what Evil lurks\n"
        + "in this ancient ruin.\n";
    dest_dir = 
        ({
        "players/pain/CASTLE/EVIL/enter_hall_2", "e",
        "players/pain/CASTLE/EVIL/enter_hall", "w",
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

