/* ***********************************************
 * room12.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 10/30/05
 * 
 *
 * **********************************************/
#include <ansi.h>

inherit "/room/room";
reset(arg)
{
  object monster;
  if(arg) 
    return ;    
  set_light(0); 
  short_desc = HIK+"Outer Boundary"+NORM; 
  long_desc  = "A dense forest looms up before the path. Scattered bones that lie in\n"+
               "the way would make a inexperienced adventurer break a leg, so be\n"+
			   "careful.\n";

		items=(
 {
 "forest", "The forest here is thicker, making travel a lot harder, as well as maneuverability",
 "bones", "Bones lay trapped between trees of this forest as though the ones trying to pass got stuck",
 "trees", "They have bones between them as though the owners got stuck",
 "path", "This path leads to the forest, but there are also bones on the ground",

 }
);

 add_listen("main", "What do you want to listen to?");
 add_listen("forest", "You hear claws scraping nearby");
 add_listen("bones", "You hear nothing coming from the bones");
 add_listen("trees", "You hear a crack once in a while as the tree branches give\n"+
                     "way from their own dead weight");

 add_listen("path", "You hear a clicking sound comming from nearby");
 
 add_taste("main", "What do you wish to taste?");
 add_taste("bones", "The bones taste clean, as though something ate everything off of it");
 add_taste("forest", "It would take too long to taste the whole forest");
 add_taste("trees", "You taste some old blood");

 add_taste("path", "You spit sand and grit out of your mouth!");

 add_smell("main", "What do you wish to smell?"); 
 add_smell("bones", "You can't smell much here since the stench of death is so strong");
 add_smell("forest", "You can't smell much here since the stench of death is so strong");
 add_smell("trees", "You can't smell much here since the stench of death is so strong");

add_smell("path", "You can't smell much here since the stench of death is so strong");
 
  dest_dir =(
 {
   /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room18", "northwest",
  "players/data/OUTERB/ROOMS/room6", "south",
  "players/data/OUTERB/ROOMS/room4", "southwest",
  "players/data/OUTERB/ROOMS/room13","east",
 }
);
  monster = clone_object("players/data/OUTERB/MOBS/gripper.c");
  move_object(monster,this_object());
  monster = clone_object("players/data/OUTERB/MOBS/gripper.c");
  move_object(monster,this_object());
}
