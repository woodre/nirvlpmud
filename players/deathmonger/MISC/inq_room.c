
#include "std.h"

reset(arg){
     if(!arg){
     set_light(1);
     extra_reset();
}
}

short(){ return "The Inquisition Room"; }
long(){
write("The room is a darkly lit room, lit only by torches attached to\n");
write("the walls.  At the front of the room are two large desks, and\n");
write("at the desks are seated two dark cloaked figures.  There is a \n");
write("gallery to the right filled with robed, angry spectators.  There\n");
write("are an assortment of torture items to the left side of the room.\n");
write("It doesn't look good for you.\n");
write("THE INQUISITION...\n");
}

extra_reset(){
if(!present("mel")){
object mel;
     mel = clone_object("obj/monster");
     mel->set_level(6000);
     mel->set_name("mel brooks");
     mel->set_alias("mel");
     mel->set_short("Mel Brooks");
     mel->set_long("Mel is here to entertain us.\n");
     mel->set_chat_chance(10);
mel->load_chat("Mel sings: The Inquisition!  What a show!\n");
     move_object(mel, this_object());
}
}
