

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A Road leading to an Evil Fortress";
    no_castle_flag = 0;
    long_desc = 
        "You are still on the road to the evil fortress...\n"
        + "You wonder what evil could lurk behind the looming drawbridge\n"
        + "As you near the castle the battle wages on even louder\n"
        + "You begin to fear that you may never return\n"
        + "Again, there is another sign by the side of the road.. you might want to read it\n"
        + "Good luck gentle warrior\n";
    dest_dir = 
        ({
        "players/pain/CASTLE/EVIL/road_3", "n",
        "players/pain/CASTLE/EVIL/road_1", "s",
        });
items = ({ "sign", "WARNING!!!:\n"
	+"You know not what evil you might encounter in this castle.\n"
	+"This castle is intended to have one player go through it at a time.\n"
	+"Throughout the castle you will find various items and windows.\n"
	+"Look at them, they should be very helpful... \n"
	+"There also is a talk command when there are non-player-characters\n"
	+"in a room... to use it type 'talk <character-name>'...\n"
	+"These characters should have good information.\n"
	+"Use these hints wisely... they may be the only things keeping you alive.\n",
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

