/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";


inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
	short_desc = "A Twisting Path.";
    no_castle_flag = 0;
    long_desc =
        "You are just northwest of where the path splits.\n"
        + "The trees stand tall above you shielding you from the sun\n"
        + "and providing a surreal setting. To the far northwest you think\n"
        + "that you can make out a cave lying at the edge of the clearing.\n"
        + "To the southeast there is a meeting of two paths.\n";

items = ({
	"path", "A narrow dirt path running through the forest",
	"cave", "A cave nestled in amoungst the trees to the far northwest",
	"trees", "Tall trees line either side of the path",
});
    dest_dir =
        ({
        "players/pain/NEW/tpath2", "northwest",
	"players/pain/NEW/path1", "southeast",
        });
    set_realm_name("Bigelow");
    set_cost(450000);
    set_lot_size(8);
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

