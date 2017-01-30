
#include "std.h"

reset(arg){
    if(!arg){
       set_light(1);
       return 1;
     }
}

init(){
     add_action("west","west");
     add_action("north","north");
     add_action("south","south");
}

west(){
     this_player()->set_pl_k(0);
     thicall_other(this_player(), "move_player",
     "west#players/deathmonger/CASTLE/station");
     return 1;
}

south(){
     this_player()->set_pl_k(0);
     call_other(this_player(), "move_player",
     "south#room/forest10");
     return 1;
}

north(){
     this_player()->set_pl_k(1);
     call_other(this_player(), "move_player",
     "north#players/deathmonger/hall2");
     return 1;
}

short(){  return "pk setting area"; }
long(){
     write("You enter the Isle of Death.  There are a couple things you \n");
     write("should know before proceeding furthur.\n");
     write("1. This entire castle is a player-killing area, meaning\n");
     write("that whether or not you player killing is set, you can \n");
     write("kill or be killed here.\n");
     write("2. Do not teleport to an area outside of the castle while\n");
     write("you are visiting the Isle of Death.  Without going into de-\n");
     write("tail, you could have your player killing permanently set if\n");
     write("you do this.\n");
     write("Welcome to the Isle of Death.\n");
}
