

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Entrance to the city among the trees";
    no_castle_flag = 0;
    long_desc = 
        "This is not what you expected too see in your normal everyday tree.\n"
        + "Instead of leaves and branches you see a town suspended in the air by\n"
        + "trees.  Large planks connect the platforms which are built around\n"
        + "large trees.  The platforms serve to hold residences, shops, and\n"
        + "various other building.  An especially large plank leads east.\n";
    dest_dir = 
        ({
        "players/molasar/FOREST/forest15", "down",
        "players/molasar/FOREST/UPPER/plat1", "east",
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

