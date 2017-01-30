/* ***********************************************

 * room17.c

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

  long_desc  = "Bushes lay scatter around, making the path difficult to\n"+

               "travel. Weeds stand in abundance, but are also just as dead.\n";





			   items=({

 "bushes", "Bushes of various sizes and heights, you even see a dead aum plant at a base",

 "path", "The path is simple and has been traveled alot in the pass",

 "weeds", "Weeds sprout in different places, but it is unusual that there isn't any living weeds",

 

});



 add_listen("main", "What do you want to listen to?");

 add_listen("bushes", "You scrape your ear against a dead branch from the bushes");

 add_listen("path", "You hear nothing along the path");

 add_listen("weeds", "The wind gently caresses throught weeds, making the only soothing sound");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("bushes", "The bushes taste moldy and rotten");

 add_taste("path", "The path tastes as though something died here");

 add_taste("weeds", "You taste the weeds and spit out a thorn");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("bushes", "You can't smell much here since the stench of death is so strong");

 add_smell("path", "You can't smell much here since the stench of death is so strong");

 add_smell("weeds", "You can't smell much here since the stench of death is so strong");





  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room10.c", "southwest",

  "players/data/OUTERB/ROOMS/room18.c","east",

  });



}

