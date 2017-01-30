/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";


inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A large open plain";
    no_castle_flag = 0;
    long_desc = 
  "You are in a large open plain.  Paths lead off to the south, east, and west\n"+
  "A large castle looms off to the north.\n";
    dest_dir = 
        ({
        "players/molasar/PLAINS/plain12", "south",
        "players/molasar/PLAINS/plain10", "east",
        "players/molasar/PLAINS/plain18", "west",
	"players/molasar/CASTLE/entry","north",
        });
    set_realm_name("Plains");
    set_cost(650000);
    set_lot_size(9);
    setup_land();
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

