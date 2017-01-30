

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
     extra_reset();
    short_desc = "Main road";
    no_castle_flag = 0;
    long_desc = 
        "This is a forest packed with evergreens and oaks and just about every kind of t   \n"
        + "tree.  You catch a glimpse of a deer leaping through the bushes.\n";
    dest_dir = 
        ({
        "/players/deathmonger/main6", "south",
        "/players/deathmonger/main8", "north",
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


extra_reset(){
object whiz;
     if(!find_living("whiz")){
     whiz = clone_object("players/deathmonger/MONSTERS/whiz");
     move_object(whiz, this_object());
     }
}
