/* ***********************************************

 * room15.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 10/30/05

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

  long_desc  = "Slime lines the walls as well as the floor, making it slippery to walk\n"+

               "on. The stench of death and decay making it hard to stand staying here.\n";

 

 

 			   items=({

 "slime", "The slime looks slippery, as well as wet from the constant moisture",

 "walls", "The walls are covered in slime and you can see a smear every few feet",

 "floor", "The floor is covered in slime as well as some interesting smears",

 "smears", "They look as though someone slipped and somehow tried to stop their fall",

});



 add_listen("main", "What do you want to listen to?");

 add_listen("slime", "You place your ear on the slime and pull back from it's cold touch");

 add_listen("walls", "The walls are covered in slime");

 add_listen("floor", "The floor is covered in slime");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("slime", "The slime has the taste of blood and mold in it");

 add_taste("walls", "You would have to taste the slime");

 add_taste("floor", "You would have to taste the slime");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("slime", "You can't smell much here since the stench of death is so strong");

 add_smell("walls", "You can't smell much here since the stench of death is so strong");

 add_smell("floor", "You can't smell much here since the stench of death is so strong");



 

  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room16","east",

  "players/data/OUTERB/ROOMS/room19","north",
   });
 }
