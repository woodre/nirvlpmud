inherit "room/room";
#include "definitions.h"

reset(arg) {

if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc=("West shore");
        long_desc=
"     A sandy path juts out to join a large body of water.  Waves tickle\n"+
"weakly upon the sandy shore.  Curving lines of dried salt lie strewn about\n"+
"on the sea shore.  Driftwood lays piled in tall heaps by the rocky cavern\n"+
"walls.  On the opposite end of the shore, a long muddy hall extends into\n"+
"darkness.  You notice the water is better lit than the rest of the cave\n"+
"because of tiny cracks within the ceiling above.  The faint light of the \n"+
"outdoors seeps into the totally unlit cave.  Gazing into the sea of water,\n"+
"you cannot determine where the water leads.\n";

   dest_dir=({
        CASTLEROOM+"/hall6.c","north"  ,
        CASTLEROOM+"/water1.c","swim"  ,
            });

   items=({
        "ceiling","     The reflection is quite pretty",
        "refletion","     You see the wave pattern of the lake surface",
        "water","     The expanse of blue water has no visible end",
        "hall","     The hall looks abysmal compared to this sight",
        "sand","     The white sand is soft and dry",
        "shore","     The shore seperates the hallway from the lake",
        "light","     The light casts an azure haze upon the lake",
        "cracks","     The cracks in the ceiling allow faint light to enter",
        "driftwood","     The driftwood is chaotically assembled upon the beach",
        "waves","     The waves roll gently upon the shore.  They pose no danger",
   });
   }   }

