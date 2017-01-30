/* ***********************************************
 * room5.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 10/30/2005
 * 
 *
 * **********************************************/
#include "ansi.h"

inherit "/room/room";
reset(arg)
{
  object monster;
  if(arg) 
    return ;    
  set_light(0); 
  short_desc = HIK+"Outer Boundary"+NORM; 
  long_desc  = "Traveling among the land of the dead, there are bones of creatures of\n"+
               "this realm everywhere, as well as the bones of unfortunate travelers.\n"+
               "There's no wind or sounds here - no signs of life.\n";
			   
			   items=({
 "cliff", "The cliff is large and looks slippery, as it is covered in blood.  It doesn't look climbable",
 "bones", "The bones look as though something was nibbling on them, as there are claw and bite marks on them",
 "marks", "Claw and bite marks cover the bones",
});

 add_listen("main", "You hear nothing. The silence is upsetting");
  
 add_taste("main", "What do you wish to taste?");
 add_taste("bones", "The bones taste terrible, and you start spitting");

 add_smell("main", "What do you wish to smell?"); 
 add_smell("bones", "You can't smell much here since the stench of death is so strong");
  dest_dir =
  ({ /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room4.c", "west",
  "players/data/OUTERB/ROOMS/room12.c", "north",
  "players/data/OUTERB/ROOMS/room6.c","east"
  });
  monster = clone_object("players/data/OUTERB/MOBS/gripper.c");
  move_object(monster,this_object());
  monster = clone_object("players/data/OUTERB/MOBS/gripper.c");
  move_object(monster,this_object());
}
