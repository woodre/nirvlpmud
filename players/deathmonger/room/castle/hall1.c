#include "defs.h"

inherit "room/room";

init(){
    ::init();
    add_action("west","west");
}
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "hall1";
    no_castle_flag = 0;
    long_desc = 
        "In front of you is a glowing sign seemingly suspended by nothing in the\n"
        + "mist.  It is written in a strange language long forgotten by your people.\n"
        + "The sign reads:\n"
        + "Beware the volcano, for it holds great dangers for those not strong \n"
        + "enough for its power.\n"
        + "There is a strange vortex to the west.\n"
        + "You stand at a crossroads, and you must decide the path to follow.\n";
    dest_dir = 
        ({
        CASTLE+"entrance", "south",
        CASTLE+"east_hall1", "east",
        CASTLE+"hall2", "north",
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

west(){
int i;
     write("Your sense of reality is becoming distorted!  Was was is no\n");
     write("more.  Your body is becoming more twisted to fit the warped \n");
     write("reality of the area.  Reality is fantasy and fantasy is\n");
     write("reality...\n");
i = random(2);
if(i == 1){
this_player()->move_player("west#players/deathmonger/west_hall1");
return 1;
}
return 1;
}
