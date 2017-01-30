/* Earwax 9/28/05:
 * Changed this to call room/board_rooms/files instead.
 * Added include of defs.h as well.
*/

#include "defs.h"

id(str){ return str == "stairway"; }
short(){ return "A dark stairway leads down"; }
long(){
    write("The stairway is quite dark.\n");
}

init(){ 
     add_action("down", "down");
}

down(){
    call_other(this_player(), "move_player",
    "down#"+BOARD_ROOMS+"change_room.c");
/*
     "down#players/deathmonger/CASTLE/change_room");
*/
     return 1;
}

reset(arg){
     if(!arg){
     move_object(this_object(), "room/adv_guild");
     }
}

