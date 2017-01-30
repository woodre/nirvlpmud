

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "You have entered a thick jungle, where you fortunately can see again.  You\n"
        + "see monkeys swinging from the trees and toucans flying about.  The buzzing\n"
        + "of insects and the humidity are unbearable.\n";
    dest_dir = 
        ({
        "/players/deathmonger/main3", "south",
        "/players/deathmonger/main5", "north",
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

