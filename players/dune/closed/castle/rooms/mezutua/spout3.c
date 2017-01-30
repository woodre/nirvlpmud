inherit "room/room";
#include "definitions.h"

int i;

void init () {
   int rnd;
   rnd = random(100);
   if (rnd <= 40) {
      target->hit_player(rnd);
      write("Just as you step into the room, fire springs up from a spout.\n");
      write("A stream of fire and brimstone splashes upon you.\n");
      write("You suffer intense pain.\n");
           }
::init();
}

reset(arg) {

if (!present("sithi")) {
   for(i = 1; i<=2; i++) 
      move_object(clone_object(CASTLEMONSTER+"/sithi_knight.c"),this_object());
   }

        if(!arg) {
        set_light(1);
        short_desc=("Fire Spouts");
        long_desc=
"     The dismal picture you see reminds you of hell.  Columns of fire and\n"+
"brimstone explode into the air from numerous spouts in the ground.  The\n"+
"temperature here is almost unbearable.\n";

   dest_dir=({
        CASTLEROOM+"/orb4.c","east"  ,
        CASTLEROOM+"/bridge.c","northwest"  ,
        CASTLEROOM+"/spout2.c","south"  ,
            });

   items=({
        "spouts","     The fire spouts measure about 2 feet in diameter",
   });
   }   }
