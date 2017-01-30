/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";


inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A path through the woods.";
    no_castle_flag = 0;
    long_desc =
        "You continue down the dirt path through the forest.\n"
        + "A ways to the north you see what you think to be a house\n"
        + "or building of some kind. To the south you see where the path\n"
        + "splinters off. The trees towering above you shade the path,\n"
        + "keeping the hot sun off of you.\n";

items = ({
	"path", "A narrow dirt path running through the forest",
	"trees", "The trees tower above you, almost blocking out the sun",
});
    dest_dir =
        ({
        "players/pain/NEW/path4", "north",
	"players/pain/NEW/path2", "south",
        });
    set_realm_name("Bigelow");
    set_cost(450000);
    set_lot_size(6);
    setup_land();
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

