inherit "room/room";
#include "definitions.h"

void init () {
      write(
"     You feel weaves of shadowvail mist wrap around you.  The\n"+
"surroundings about you blur and change form.\n");
::init();
}

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc=("Center of Lake of Magma");
        long_desc=
"     A boiling lake of magma completely encircles you.  Pillars of blackened\n"+
"rock jut out from the lake, providing the only way to travel across the fiery\n"+
"inferno.  However, the pillars are spaced rather far apart.  You would have\n"+
"to jump to each one.  You better not lose your balance...\n"+
"A stairway leads back up to the doorway.\n";

   dest_dir=({
        CASTLEROOM+"/lava4.c","north"  ,
        CASTLEROOM+"/lava6.c","east"  ,
        CASTLEROOM+"/lava8.c","south"  ,
        CASTLEROOM+"/lava1.c","west"  ,
        CASTLEROOM+"/fire.c","up"  ,
            });

   items=({
        "lake",
"     The lake of magma is huge, covering about half a square mile.\n"+
"As you look closer, you can see movements in the magma \n"+
"characteristic of humanoid-like beings",
        "pillars","     The pillars stand about 80 feet above the lake",
        "rock","     The rock is some sort of durable obsidian",
   });
   }   }
