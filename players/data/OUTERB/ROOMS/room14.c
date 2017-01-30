/* ***********************************************

 * room14.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 10/30/05

 * 

 *

 * **********************************************/

#include "ansi.h"



inherit "room/room";

reset(arg) {

  object monster;

  if(arg) 

    return ;    

  set_light(0); 

  short_desc = HIK+"Outer Boundary"+NORM; 

  long_desc  =



 "A waterfall flows here, no life, and its not healthy to drink. The air carries\n"

+"a sound, but the source can't be found and is rather chilling to hear \n";

 

 			   items=({

 "waterfall", "The waterfall looks filty and full of bones at it's base",

 "bones", "The bones in the waterfall look diseased and rotten",

 

});



 add_listen("main", "What do you want to listen to?");

 add_listen("waterfall", "You listen to the waterfall and hear a slow slurping sound");

 add_listen("bones", "You dont' want to get too close to the water to listen to the bones");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("waterfall", "You think twice before tasting something so foul");

 add_taste("bones", "You would have to enter the water to taste the bones and think not to bother");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("waterfall", "You can't smell much here since the stench of death is so strong");

 add_smell("bones", "You can't smell much here since the stench of death is so strong");

  

  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room13", "west",

  "players/data/OUTERB/ROOMS/room7","southeast"

  });



}

