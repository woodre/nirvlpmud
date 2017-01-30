/* ***********************************************
 * room13.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 10/30/05
 * 
 *note - want snakevine to do something to a person when they look at it
 * **********************************************/
#include "ansi.h"

inherit "/room/room";
reset(arg) {
  object monster;
  if(arg) 
    return ;    
  set_light(0); 
  short_desc = HIK+"Outer Boundary"+NORM; 
  long_desc  = "Dead, fallen tree lay scattered around while the few trees left\n"+
               "standing give off a strange odor of death. Nothing seems right here.\n";
			   
			   items=({
 "forest", "The forest here is thicker, making travel alot harder as well as maneuverability",
 "bones", "Bones lay trapped between trees of this forest as though the ones trying to pass got stuck",
 "trees", "They have bones between them as though the owners got stuck",
 
});

 add_listen("main", "What do you want to listen to?");
 add_listen("forest", "You hear claws scrapping nearby");
 add_listen("bones", "You hear nothing comming from the bones");
 add_listen("trees", "You hear a crack once in awhile as the trees weight gives alway");
 
 add_taste("main", "What do you wish to taste?");
 add_taste("bones", "The bones taste clean as though something ate everything off it it");
 add_taste("forest", "It would take too long to taste the whole forest");
 add_taste("trees", "You taste some old blood");

 add_smell("main", "What do you wish to smell?"); 
 add_smell("bones", "You can't smell much here since the stench of death is so strong");
 add_smell("forest", "You can't smell much here since the stench of death is so strong");
 add_smell("trees", "You can't smell much here since the stench of death is so strong");

  dest_dir =
  ({ /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room14", "east",
  "players/data/OUTERB/ROOMS/room12","west"
  });

}