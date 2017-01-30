#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
At one time this was once a grand hall of some kind.  Time, elements and other\n\
robbers have stripped anything of value from here.  Now all that remains is \n\
the dried shattered bones of goblins and dwarves.  Though clear exits to the\n\
north, east and west can be seen the southern route is blocked by a large cave \n\
in.\n"); 
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "bones", "Shattered and splintered remains of foes from long ago when the hold fell",
         "bone", "Remains of foes from long ago",
         "hall", "Once a grand hall now only a ruin",
         "cave in", "Large rocks and stone form an impassable barrier to the south"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh3.c", "north",
         "players/khrell/area/underways/undermdh7.c", "east",
         "players/khrell/area/underways/undermdh8.c", "west"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
