#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
Here sits what once was a grand hallway intersection. A high domed ceiling\n\
towers above all below it.  Faded depictions of many old battles give one a\n\
sense that at one time this was a powerful hold.  An occasional gouge, chip\n\
or scratch gives mute testmony that a battle was fought in here.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "depictions", "A vast menagerie of many battles undertaken by the dwarves",
         "gouge", "A sad fact of looting and war have created this mar",
         "chip", "This appears to have been made by a weapon strike",
         "scratch", "This was made by some sort of bladed weapon",
         "hallway", "Part of the intersection",
         "depiction", "Carved images showing old battles by the dwarven kings",
         "ceiling", "Built well above your head, must have been quite a feat for the dwarves"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh10.c", "west",
         "players/khrell/area/underways/undermdh12.c", "east",
         "players/khrell/area/underways/undermdh13.c", "up"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
