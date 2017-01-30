inherit "room/room";
#include "definitions.h"

int i;

void init () {
        int rnd;
        rnd = random(100);
        if (rnd <= 25) {
           target->hit_player(rnd/2);
           write("Ouch, you stepped on a sharp rock!\n");
           }
::init();
}

reset(arg) {

if (!present("orc")) {
   for(i = 1; i<=7; i++) 
      move_object(clone_object(CASTLEMONSTER+"/orc.c"),this_object());
   }
if (!present("scarnose"))
   move_object(clone_object(CASTLEMONSTER+"/scarnose.c"),this_object());

        if(!arg) {
        set_light(0);
        short_desc=("Eastern Tube");
        long_desc=
"     A tunnel of jagged rock extends into the darkness.  The rough walls\n"+
"are lined with stalagmites and stalagtites.  The spear-like floor\n"+
"makes travel difficult.\n";

   dest_dir=({
        CASTLEROOM+"/east3.c","east"  ,
        CASTLEROOM+"/orb1.c","north"  ,
        CASTLEROOM+"/east1.c","west"  ,
            });

   items=({
        "walls","     The walls are sharply edged with pointed rock",
        "stalagmites","     The stalagmites jut forcefully from the floor",
        "stalagtites","     The stalagtites hang sharply from the ceiling",
        "floor","     The floor is covered with sharp stalagmites",
   });
   }   }
