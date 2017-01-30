#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
Here are the obvious signs of a great battle.  Broken furniture, shattered\n\
stoneworks, damaged statues and the long dead remains of dwarves and goblins.\n\
Oddly the remains have been moved to the sides of the room and left there to\n\
decay.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "furniture", "Various items of dwarven comfort now all but debris",
         "stoneworks", "Many, former, works of art created by dwarves",
         "statues", "Many carvings, once proud depictions of lords, now marred and defaced",
         "remains", "Rusted armor and moldy bones from both combatants",
         "stonework", "Former works of art created by the dwarves",
         "statue", "Once proud depictions of a lord, now defaced",
         "armor", "Rusted and barely held together",
         "bones", "Skeletal remains of both dwarves and goblins",
         "bone", "Remains of dwarves and goblins",
         "carvings", "Once masterful works of art, now deliberately destroyed",
         "art", "Created by masterful dwarven artisans, now destroyed",
         "debris", "The remains of a fierce fight",
         "room", "A fierce battle was waged here long ago"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh11.c", "down",
         "players/khrell/area/underways/undermdh15.c", "south"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
