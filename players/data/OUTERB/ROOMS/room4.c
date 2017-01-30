/* ***********************************************
 * room4.c
 *
 * Creator - Data
 * 
 * Date of File Completion - 10/30/2005
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
  long_desc  =
 "Stepping through the green light and into the land of the dead the\n"+
 "senses are immediately assaulted. Dead trees lay scattered about as\n"+
 "though something tore them apart. The presence of a meer mortal stirs\n"+
 "what lives here.\n";

items=(
 {
 "light", "A unusual green light covers the land",
 "trees", "The trees, which were once full of life, are now dead and fallen",
 
 }
);

 add_listen("main", "What do you want to listen to?");
 add_listen("light", "You hear a low hum in your ears.  It is slightly stimulating");
 add_listen("trees", "You hear an occasional crack as the dead weight of the trees work further to bring them down");
  
 add_taste("main", "What do you wish to taste?");
 add_taste("light", "You can't taste the green light");
 add_taste("trees", "You gasp as you get a splinter in your mouth");

 add_smell("main", "What do you wish to smell?"); 
 add_smell("light", "You can't smell much here since the stench of death is so strong");
 add_smell("trees", "You can't smell much here since the stench of death is so strong");
  dest_dir =
  ({ /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room5.c", "east",
  "players/data/OUTERB/ROOMS/room12.c","northeast",
  "players/data/OUTERB/ROOMS/entrance.c", "south"
  });
}