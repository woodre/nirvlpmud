inherit "room/room";
#include "definitions.h"

int c;

reset(arg) {

  if (!present("sithi")) {
    for(c=1;c<=9;c++)
      move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());
    }

        if(!arg) {
        set_light(1);
        short_desc="Cleric residences";
        long_desc=
"     You enter a large room filled with wooden partitions and cots.\n"+
"Bags and wierd looking tools are stuffed into each partition.\n"+
"Each partition has a symbol upon it.  Different symboled partitions\n"+
"have different sizes.  This must be the home of all the temple\n"+
"residents, or at least one of the homes.\n";

   dest_dir=({
        CASTLEROOM+"/room3.c","west"  ,
        CASTLEROOM+"/room4.c","north"  ,
            });

   items=({
        "cots","     They serve as moderately comfy beds",
        "partitions","     These are the rooms of the sithi",
   });
   }   }
