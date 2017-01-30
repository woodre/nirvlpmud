#include "std.h"
object wiz, dude;
reset(){
    set_light(1);
    extra_reset();
}
extra_reset() {
if (!wiz || !living(wiz)) {
     wiz = clone_object("players/deathmonger/MONSTERS/wiz");
     move_object(wiz, this_object());
}
}

init(){
    add_action("north","north");
    add_action("south","south");
    dude = this_player();
}

query_dude(){ return dude; }
north(){
   this_player()->move_player("north#players/deathmonger/poppies");
   return 1;
}

south(){
   this_player()->move_player("south#players/deathmonger/CASTLE/oz/dorothy");
   return 1;
}

short(){ return "The Wizard of Oz"; }
long(){ 
    write("You have entered the inner sanctum of the Wizard of Oz. \n");
    write("The room has a high ceiling, and the wizard is echoing \n");
    write("stuff. You are overwhelmed by the fire and brimstone. The Wizard\n");
    write("wants to know what you're doing here.\n");
    write("There are two obvious exits: north and south.\n");
}
