inherit "room/room";
#include "definitions.h"

int f;

reset(arg) {

    if(!present("sithi")) {
       for(f=1;f<=2;f++)
       move_object(clone_object(CASTLEMONSTER+"/sithi_priest.c"),this_object());
       }
     if (!present("sithi"))
     move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),this_object());

        if(!arg) {
        set_light(1);
        short_desc="Gathering place";
        long_desc=
"     You come upon a rather large area filled with tables and chairs.\n"+
"Sofas line the side walls.  Crumbs of food and whatnot dirty the floor.\n"+
"To the south, you see what looks like a living area for the local\n"+
"residents.  To the east, you see an even larger living area.  Venturing\n"+
"into these areas would probably not be a good idea for the less than\n"+
"powerful.\n";

   dest_dir=({
        CASTLEROOM+"/sithichambers.c","south"  ,
        CASTLEROOM+"/sithiguards.c","east"  ,
        CASTLEROOM+"/room3.c","southwest"  ,
            });

   items=({
        "crumbs","     You see little pieces of garbage",
   });
   }   }
