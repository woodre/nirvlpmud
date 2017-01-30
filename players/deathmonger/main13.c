

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Pyramid";
    no_castle_flag = 0;
    long_desc = 
        "A Great Pyramid stands here, defiant of the harsh climate.  Two massive\n"
        + "stone Sphinxes stand here, guarding the entrance of the pyramid.  \n";
    dest_dir = 
        ({
        "/players/deathmonger/main12", "south",
        "/players/deathmonger/main14", "north",
        "/players/deathmonger/CASTLE/pyramid/entrance", "enter",
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

