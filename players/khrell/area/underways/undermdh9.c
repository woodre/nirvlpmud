#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
Once a great weapons store room, it now lays completely empty stripped of anything\n\
of value.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({});
   dest_dir = ({
         "players/khrell/area/underways/undermdh8.c", "east"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
