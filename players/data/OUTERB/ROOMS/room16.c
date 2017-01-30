/* ***********************************************

 * room16.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 11/20/05

 * 

 *

 * **********************************************/

#include "ansi.h"



inherit "/room/room";

reset(arg) {

  object monster;

  if(arg) 

    return ;    

  set_light(0); 

  short_desc = HIK+"Outer Boundary"+NORM; 

  long_desc  = "The cave opens up to a spacious room with a hole in the ceiling.\n"+

               "A pile of bones litter the floor, perhaps some preditor lives here.\n";

  

  			   items=({

 "floor", "The floor has bones all over it",

 "hole", "The hole once would of let in light and fresh air",

 "pile", "The pile of bones look as though a preditor left them, some even have tooth marks",

 

});



 add_listen("main", "What do you want to listen to?");

 add_listen("hole", "You listen to the hole and hear a soft breeze");

 add_listen("pile", "You hear a soft crackling as though bugs are eatting the marrow");

 add_listen("floor", "You listen to the floor and hear footsteps");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("hole", "You taste the hole and spit out bits of dust");

 add_taste("pile", "The bone pile tastes reasonably decent so it must be fresh");

 add_taste("floor", "You taste the floor taste blood");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("hole", "You can't smell much here since the stench of death is so strong");

 add_smell("pile", "You can't smell much here since the stench of death is so strong");

 add_smell("floor", "You can't smell much here since the stench of death is so strong");



    

  

  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room15", "west",

  "players/data/OUTERB/ROOMS/room19", "northwest",

  "players/data/OUTERB/ROOMS/room8", "exit",

  });



}

