/* 10/11/05 Earwax: Made this into land. */

inherit "/players/earwax/housing/land.c";
inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A road towards a small town.";
    no_castle_flag = 0;
    long_desc =
        "The road leads north towards the town's square and south\n"
        + "back towards Nirvana's main village road. You are joined on\n"
        + "the road by a few merchants going to the shops.\n";

items = ({
	"road", "A well-travelled road towards the town",
});
    dest_dir =
        ({
        "players/pain/NEW/square", "north",
        "players/pain/NEW/road1", "south",
        });
    set_realm_name("Bigelow");
    set_cost(750000);
    set_lot_size(9);
    setup_land();
if(!present("merchant"))
move_object(clone_object("/players/pain/NEW/mon/merchant"),this_object());
}

init() {
	::init();
}

realm() { return "NT"; }


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

