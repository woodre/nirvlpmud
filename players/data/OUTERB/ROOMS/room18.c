/* ***********************************************

 * room18.c

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

  long_desc  = "The fallen trees are thinner here, making the path a little easier to\n"+

               "follow. The silence that penetrates this darkness gives a bad feeling.\n";





			   items=({

 "trees", "The trees are thinner here, making it easier to see around you with your light",

 "path", "The path is easier to manage as there is more to see without so many trees",

 "darkness", "The darkness is everywhere and not even your light will eluminate it",

 

});



 add_listen("main", "What do you want to listen to?");

 add_listen("trees", "You place an ear against the tree and hear only a creaking sound");

 add_listen("path", "You place an ear to the path and hear nothing nearby");

 add_listen("darkness", "You strain your ears to listen to the darkness and hear some strange sounds");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("trees", "You taste a tree and spit out a dead bug from between your teeth");

 add_taste("path", "The path tastes moldy but not bloody, your heart skips a beat");

 add_taste("darkness", "How can you taste the darkness?");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("trees", "You can't smell much here since the stench of death is so strong");

 add_smell("path", "You can't smell much here since the stench of death is so strong");

 add_smell("darkness", "You can't smell much here since the stench of death is so strong");





  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room17.c", "west",

  "players/data/OUTERB/ROOMS/room12.c","southeast",

  });



}

