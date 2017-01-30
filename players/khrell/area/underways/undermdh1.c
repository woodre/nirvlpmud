#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
 A strange glow appears from the walls, giving a passable illumination\n\
to this otherwise nondescript corridor.  Signs of battle can be seen \n\
up and down this passage.  Broken weapons and shattered armor can be \n\
seen, along with the splintered bones of former combatants.          \n");   
   set_light(1);
   add_listen("main", "You hear metallic grinding noises.\n");
   add_smell("main", "You smell dust and want to sneeze.\n");
   items = ({
         "weapons", "Rusted and shattered axes, hammers and swords lay strewn about",
         "weapon", "Rusted and shattered axes, hammers and swords lay strewn about",
         "armor", "Various unscavenged parts of long used armor now totally unsalvageable",
         "corridor", "This corridore goes north and south",
         "passage", "This passage goes north and south",
         "glow", "A source of unknown means that light this area",
         "bones", "Time and other things have reduced the skeletons to splintered fragments",
         "bone", "Time and other things have reduced the skeletons to splindered fragments",
         "wall", "It seems to glow from unknown means",
         "walls", "They glow from an unknown source"
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm12.c", "out",
         "players/khrell/area/underways/undermdh2.c", "north",
         "players/khrell/area/underways/undermdh3.c", "south"});
   return 1; }
