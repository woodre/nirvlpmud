

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Field of Poppies";
    no_castle_flag = 0;
    long_desc = 
        "You enter an intoxicating field of poppies.  You want to just sit here and\n"
        + "rest awhile.  Well, eventually the poppies will be intoxicating...\n";
    dest_dir = 
        ({
        "/players/deathmonger/CASTLE/oz/wiz", "south",
        "/players/deathmonger/CASTLE/oz/witch", "west",
        "/players/deathmonger/CASTLE/oz/lion", "north",
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


init(){
     drunk();
     ::init();
}

drunk(){
if(!this_player()) return 1;
     this_player()->add_alcohol(100);
     write("You feel tired and mellow all of a sudden.\n");
     return 1;
}
