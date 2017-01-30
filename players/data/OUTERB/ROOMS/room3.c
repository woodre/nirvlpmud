/* ***********************************************

 * room3.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 10/30/2005

 * 

 *

 * **********************************************/

#include <ansi.h>



inherit "room/room";

reset(arg) {

  object monster;

  if(arg) 

    return ;    

  set_light(0); 

  short_desc = HIK+"Outer Boundary"+NORM; 

  long_desc  =

 "Bones lay scattered about, as though discarded like trash. To the west there\n"

+"a cliff, one would wonder if they can find a way around it before getting caught.\n";



items=({

 "cliff", "The cliff looks large and slippery as it is covered in blood, it doesn't look climbable",

 "bones", "The bones look as though something was nibbling on them as there are claw and bite marks on them",

 "marks", "small claw and bite marks cover the bones",

});



 add_listen("main", "What do you want to listen to?");

 add_listen("cliff", "You hear clicking sounds comming from the cliff");

 add_listen("bones", "You hear nothing comming from the bones");

 add_listen("marks", "You hear nothing comming from the marks");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("cliff", "The cliff tastes bloody, perhaps something fell to its demise.");

 add_taste("bones", "The bones taste very bad.");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("cliff", "You can't smell much here since the stench of death is so strong");

 add_smell("bones", "You can't smell much here since the stench of death is so strong");

 

  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room9", "north",

  "players/data/OUTERB/ROOMS/room2.c","west",

  });



}

