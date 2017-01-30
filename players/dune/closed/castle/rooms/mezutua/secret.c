inherit "room/room";
#include "definitions.h"

void init () {
        add_action("squeeze","squeeze");
::init();
}

reset(arg) {
        if(!arg) {
        set_light(0);
        short_desc=("Eastern Tube");
        long_desc=
"     The tunnel gets narrower as you proceed eastward.\n"+
"But soon the path becomes unpassable.  Two large \n"+
"stalagmites block your way.\n";

   dest_dir=({
        CASTLEROOM+"/east4.c","northwest"  ,
            });

   items=({
        "stalagmites",
"     The two stalagmites block off further eastward passage.\n"+
"Normally you might be tempted to head back, but you \n"+
"see the cavern open up beyond the stalagmites.  You'll \n"+
"have to figure out a way to get past these",
   });
   }   }


int squeeze (string str) {
  string blee, blah;
  if (!str) { write("Squeeze through what?\n"); return 1; }
  if (sscanf(str, "through%sstalagmit%s", blee, blah)) {
      write("You squeeze right through the stalagmites.\n");
      say("Squeezes through stalagmites.\n");
      move_object(TP, CASTLEROOM+"/orb3.c");
      return 1;} 
  write("squeeze through what?\n");
  return 1;
}
