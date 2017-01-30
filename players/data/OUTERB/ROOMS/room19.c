/* ***********************************************

 * room19.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 11/28/05

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

  long_desc  = "The cave becomes more narrow as foot steps echo the walls. A sound\n"+

               "can be heard comming from the room ahead as a breeze is felt.\n";



			   items=({

 "walls", "The walls are covered in slime as well as some blood",

 "room", "You see faint movement up ahead",

 "slime", "The slime has splatters on blood on it",

 "blood", "You look at the blood and see splatters of it against the slime covered walls",

});



 add_listen("main", "What do you want to listen to?");

 add_listen("walls", "You place an ear against the wall and then start digging slime out of your ear");

 add_listen("slime", "You place an ear against the slime and shutter at how cold it is");

 add_listen("blood", "You place an ear against the blood, but hear nothing");

 add_listen("room", "You strain your hearing to listen to the next room and hear claws scrapping");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("walls", "You taste blood and slime on the walls...YUCK");

 add_taste("blood", "You gently taste the blood avoiding the slime and notice that it doesn't taste human");

 add_taste("slime", "You taste the slime and figure that whatever is ahead is isn't human");

 add_taste("room", "You can't taste the room from here");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("walls", "You can't smell much here since the stench of death is so strong");

 add_smell("blood", "You can't smell much here since the stench of death is so strong");

 add_smell("slime", "You can't smell much here since the stench of death is so strong");

 add_smell("room", "You can't smell much here since the stench of death is so strong");



  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room15.c", "south",

  "players/data/OUTERB/ROOMS/room20.c", "northeast",

  "players/data/OUTERB/ROOMS/room16.c","southeast",

  });

  monster = clone_object("players/data/OUTERB/MOBS/heart_hound.c");

  move_object(monster,this_object());

  monster = clone_object("players/data/OUTERB/MOBS/heart_hound.c");

  move_object(monster,this_object());

}

