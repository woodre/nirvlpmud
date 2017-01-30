#include "defs.h"

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Foyer of Deathmonger's Castle";
    no_castle_flag = 0;
    long_desc = 
        "A crimson mist obscures your vision. There seems to be no reality here to\n"
        + "orient yourself with; no ground, no sky...no up, no down.\n"
        + "You can hear the rumbling of a train to the west.  The only visible\n"
        + "landmark is the top of a fiery volcano far to the north.\n";
    dest_dir = 
        ({
        "/room/south/sforst5", "south",
        CASTLE+"hall1", "north",
        CASTLE+"station", "west",
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

