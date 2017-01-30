inherit "room/room";
#include "definitions.h"

reset(arg) {

  if (!present("sithi")) {
    move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());
    move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());
}

        if(!arg) {
        set_light(1);
        short_desc="Main hall, southern end";
        long_desc=
"     The ceiling is very high in here.  You must have entered the\n"+
"main hall.  Vases line the walls, and wicker rugs lie upon the floor.\n"+
"Upon the very ceiling of the hall, you see a large mural of three horns\n"+
"surrounded by blazing fire.  To the north, the long hall continues.\n"+
"Way to the north, you can see a circular structure upon the ground.\n"+
"The walls in the hall are filled with words and symbols in a strange\n"+
"language.  All the writing seems to have been done in blood.\n";

   dest_dir=({
        CASTLEROOM+"/room2.c","north"  ,
        CASTLEROOM+"/room3.c","east"  ,
        CASTLEROOM+"/guardslord.c","west"  ,
            });

   items=({
        "blood",
"     The blood sticks strangely to the wall, as if some force has binded\n"+
"it to service",
        "mural","     The mural is quite simple, yet evil",
   });
   }   }
