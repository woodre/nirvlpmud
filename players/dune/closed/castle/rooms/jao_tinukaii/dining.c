inherit "room/room";
#include "definitions.h"

reset(arg) {

   if(!present("sithi")) {
       move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),this_object());
       move_object(clone_object(CASTLEMONSTER+"/sithi_man.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc="Dining hall";
        long_desc=
"     You have entered a dining area.  Numerous chairs are lined up\n"+
"next to a very long table.  It looks as if the dinner party must\n"+
"have just eaten.  There are bones and pieces of other flesh lying\n"+
"scattered upon the table, not to mention the ground as well.\n"+
"You smell a wine-like scent coming from the table.  As you look\n"+
"for the exact source, you realize it is spilled drink running in\n"+
"streams all along the floor.\n";

   dest_dir=({
        CASTLEROOM+"/guardslord.c","south"  ,
        CASTLEROOM+"/room2.c","east"  ,
            });

   items=({
        "streams","     Streams of a wine-like drink",
        "flesh","     The flesh is indistinguishable",
        "bones","     The bones appear to be of humanoid origin",
   });
   }   }
