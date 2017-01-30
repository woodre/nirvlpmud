

#include "std.h"

reset(arg){
     if(!arg){
      set_light(1);
     extra_reset();
     }
}

object dude, svirf;

extra_reset(){
     if(!present("svirfneblin")){
       svirf = clone_object("players/deathmonger/MONSTERS/cleric");
       move_object(svirf, this_object());
    }
}

init(){
     add_action("up","up");
     dude = this_player();
}

query_dude(){ return dude; }

short(){ return "Svirfneblin Cleric's HQ"; }
long(){ 
 write("You have entered the chambers of the High Cleric of the Svirfneblins\n");
 write("He probably wants to know what you're doing here.\n");
 write("There is one obvious exit: up.\n");
}

up(){
     call_other(this_player(), "move_player",
      "up#players/deathmonger/UNDERDARK/svirf/entrance.c");
     return 1;
}
