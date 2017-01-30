/* ***********************************************

 * room11.c

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

"A small indentation in the land. There used to be some kind of water\n"+

"way here, or a stream but its all dried up. Something foul fills the air\n"+

"from either a recent kill or too much death.\n";



items=({

 "indentation", "A large indentation in the land that used to be a water way",

 "land", "The land has an aura of death and decay",



});



 add_listen("main", "What do you want to listen to?");

 add_listen("indentation", "The water sounds thick with sludge");

 add_listen("land", "You hear a clicking sound comming from the west, and from the south");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("indentation", "It tastes rather moldy");

 add_taste("land", "You spit out the dirt as you foolishly try to taste the land");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("indentation", "You can't smell much here since the stench of death is so strong");

 add_smell("land", "You can't smell much here since the stench of death is so strong");



  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room8.c", "east",

  "players/data/OUTERB/ROOMS/room14.c", "northwest",

  

  });

  monster = clone_object("players/data/OUTERB/MOBS/heart_hound.c");

  move_object(monster,this_object());

  monster = clone_object("players/data/OUTERB/MOBS/heart_hound.c");

  move_object(monster,this_object());

}

