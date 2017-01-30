#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
The east guard room has all the fixings that one would expect of the\n\
occupants.  Many arrow slits, weapon racks and beds fill the room.\n\
Anything of value has been long ago looted.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "slits", "Used to fire or discharge arrows without worry of return fire",
         "rack", "Once it stored axes, hammers or missile weapons now dusty and empty",
         "bed", "Nothing but a rusted frame and springs",
         "fixings", "Arrow slits, weapon racks, and rusted bed frames",
         "room", "Once occupied by dwarven guards",
         "racks", "Once storing axes, hammers and missile weapons now dusty and empty",
         "beds", "Rusted frames and springs are all that remain"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh15.c", "west"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
