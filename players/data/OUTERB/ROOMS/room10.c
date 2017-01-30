/* ***********************************************

 * room10.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 10/30/05

 * 

 *

 * **********************************************/

#include <ansi.h>



inherit "/room/room";

reset(arg) {

  object monster;

  if(arg) 

    return ;    

  set_light(0); 

  short_desc = HIK+"Outer Boundary"+NORM; 

  long_desc  ="Still no signs of normal life as foot steps echo in the darkness. Dead\n"+

              "twigs and leaves litter the floor, making it impossible to move silently.\n";



			   items=({

 "darkness", "The darkness covers the majority of the area, and is only illuminated by your light",

 "twigs", "The twigs are broken and crushed as though there was a path here",

 "leaves", "The leaves are wet with moisture",

 

});



 add_listen("main", "What do you want to listen to?");

 add_listen("darkness", "You strain your ears but aren't able to hear anything");

 add_listen("twigs", "You place an ear against a twig and it snaps");

 add_listen("leaves", "You place an ear to the leaves and feel the wetness");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("darkness", "You flicker your tongue in the air like a snake and can only taste death");

 add_taste("twigs", "You taste the twigs and cut your tongue");

 add_taste("leaves", "You taste some leaves and spit furiously as the aweful taste fills your mouth");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("darkness", "You can't smell much here since the stench of death is so strong");

 add_smell("twigs", "You can't smell much here since the stench of death is so strong");

 add_smell("leaves", "You can't smell much here since the stench of death is so strong");





  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room9.c", "west",

  "players/data/OUTERB/ROOMS/room17", "northeast",

  "players/data/OUTERB/ROOMS/room11.c","east"

  });

}

