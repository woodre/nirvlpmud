/* ***********************************************

 * room2.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 8/2/2004

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

  long_desc  =

 "A dead end here, a cliff climbs endlessly, claws can be heard from above\n"+

 "scrapping while moans can be heard all around you, making the air seem as a chill.\n";



items=({

 "cliff", "The cliff looks small but is unusually discolored from here. It doesn't look climbable",



});



 add_listen("main", "What do you want to listen to?");

 add_listen("cliff", "You hear nothing from the cliff");



 add_taste("main", "What do you wish to taste?");

 add_taste("cliff", "The cliff tastes bloody, perhaps something fell to its demise");

 add_taste("blood", "The blood tastes coppery and old...DISCUSTING!!");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("cliff", "You can't smell much here since the stench of death is so strong");

 add_smell("blood", "You can't smell much here since the stench of death is so strong");

 dest_dir =



  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room3.c", "east",

 

  });

  monster = clone_object("players/data/OUTERB/MOBS/father.c");

  move_object(monster,this_object());

}

