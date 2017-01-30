inherit "room/room";
#include "definitions.h"

int b;

reset(arg) {

   if (!present("sithi")) {
     for(b=1;b<=4;b++)
       move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());
     }

        if(!arg) {
        set_light(1);
        short_desc="Pews";
        long_desc=
"     Rows and rows of ebony pews line up before you.  Countless numbers\n"+
"of candles line the walls.  Devilish images and symbols lay painted\n"+
"upon the walls and ceilings.  You smell blood in the air.\n"+
"Along the pews, various clergy equipment lay upon miniature tables.\n"+
"To the north, stairs lead up to a slightly raised area.  You hear the\n"+
"sparking and cracking of fire.  You see the top of a huge statue\n"+
"ahead, but all below it is obscured by the stairs and the distance\n"+
"between.\n";

   dest_dir=({
        CASTLEROOM+"/altar.c","north"  ,
        CASTLEROOM+"/room3.c","exit"  ,
            });

   items=({
        "pedestal","     It is far to the north",
        "pews","     They allow for a large seating capacity",
        "symbols","     The symbols are of three horns",
        "images","     The images are mainly of diabolic figures",
   });
   }   }
