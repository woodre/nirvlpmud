#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
This was at one time some private residence.  Now all that remains is rubble\n\
dust and cobwebs.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "rubble", "Shattered stonework and other various fixtures",
         "dust", "The culmination of years of disuse",
         "cobwebs", "Old spider webs covered in dust",
         "cobweb", "An old spider web covered in dust"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh6.c", "west"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
