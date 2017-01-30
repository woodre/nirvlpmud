inherit "room/room";
#include "definitions.h"

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

if (!present("darkshadow")) {
      move_object(clone_object(CASTLEMONSTER+"/darkshadow.c"),this_object());
   }

        if(!arg) {
        set_light(0);
        short_desc=("Eastern Tube");
        long_desc=
"     A tunnel of jagged rock extends into the darkness.  The rough walls\n"+
"are lined with stalagmites and stalagtites.  The spear-like floor\n"+
"makes travel difficult.  It gets warmer to the north... that's funny, this\n"+
"volcano is supposed to be extinct.\n";

   dest_dir=({
        CASTLEROOM+"/east4.c","east"  ,
        CASTLEROOM+"/spout1.c","north"  ,
        CASTLEROOM+"/east2.c","west"  ,
            });

   items=({
        "walls","     The walls are sharply edged with pointed rock",
        "stalagmites","     The stalagmites jut forcefully from the floor",
        "stalagtites","     The stalagtites hang sharply from the ceiling",
        "floor","     The floor is covered with sharp stalagmites",
   });
   }   }
