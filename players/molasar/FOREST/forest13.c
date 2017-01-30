/* 10/11/05 Earwax: Converted to land. */

inherit "/players/earwax/housing/land.c";


inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A great forest";
    no_castle_flag = 0;
    long_desc = 
        "You are in a great forest.  To the east you can see a tree which towers\n"
        + "above all other trees in the forest.  It must have some importance.\n";
    dest_dir = 
        ({
        "players/molasar/FOREST/forest14", "north",
        "players/molasar/FOREST/forest12", "south",
/* moved exit to forest15 from here to forest17  -Eurale  4/8/97
        "players/molasar/FOREST/forest15", "east",
*/
        "players/molasar/FOREST/forest3", "west",
        });
    set_realm_name("Forest");
    set_cost(300000);
    set_lot_size(2);
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

