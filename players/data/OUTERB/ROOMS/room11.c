/* ***********************************************

 * room11.c

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

  long_desc  = "Trees are scattered around the immediate area, making it difficult\n"+

               "for a traveler to walk safely without bumping into a tree or two.\n";

			   

			   items=({

 "trees", "Tall and grey with death, trees litter the floor and lay against one another",

 "area", "The area is filled with dead trees, be careful as something might be among them",



});



 add_listen("main", "What do you want to listen to?");

 add_listen("trees", "You hear a whisper comming from the trees");

 add_listen("area", "You hear the sound of wind but can't feel it, your skin starts to crawl");

 

 add_taste("main", "What do you wish to taste?");

 add_taste("trees", "You would rather not try to taste the tree");

 add_taste("area", "The area tastes evil");



 add_smell("main", "What do you wish to smell?"); 

 add_smell("trees", "The trees smell as though something evil killed them");

 add_smell("area", "You hold your nose high and test the air then shutter");



  dest_dir =

  ({ /* needed to signify an array */

  "players/data/OUTERB/ROOMS/room10", "west",

  });

  monster = clone_object("players/data/OUTERB/MOBS/shadows.c");

  move_object(monster,this_object());

  monster = clone_object("players/data/OUTERB/MOBS/shadows.c");

  move_object(monster,this_object());


}
