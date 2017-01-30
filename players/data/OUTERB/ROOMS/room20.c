/* ***********************************************

 * room20.c

 *

 * Creator - Data

 * 

 * Date of File Completion - 11/20/05

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

  long_desc = "The cave ends here, bringing much relief. Assorted bones litter\n"+

               "the floor and apparently no attempt was made to hide them.\n";



			   items=({

 "bones", "There are alot of bones here, some even have meat still on them",

 "floor", "The floor is covered in bones and you can only find a few places to step without stepping on a bone",

 "meat", "You look at the meat on the bones and notice that with that much it was human",

 

});



 add_listen("main", "What do you want to listen to?");

 add_listen("floor", "You find a bare place and put your ear against it, hearing some strange sounds");

 add_listen("bones", "You hear a trickling of a liquid from the bones...its probally blood");

 add_listen("meat", "You put an ear to the meat and hear a crunching sound");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("bones", "You taste blood and flesh on some of the bones");

 add_taste("meat", "It tastes bloody and fetid as though whatever was eatting it has bad teeth");

 add_taste("floor", "You taste old blood on the floor");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("bones", "You can't smell much here since the stench of death is so strong");

 add_smell("meat", "You can't smell much here since the stench of death is so strong");

 add_smell("floor", "You can't smell much here since the stench of death is so strong");





  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room19.c", "southwest",



  });

  monster = clone_object("players/data/OUTERB/MOBS/mother.c");

  move_object(monster,this_object());



}

