#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
This was once a central chamber linking the great hall, main entrance and\n\
guard rooms.  To the south lays a great door, splintered and shattered.  \n\
The doors to the guard rooms lay open.  The siege has turned this into all\n\
but a mute testmony to what happened here.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "door", "A great wooden and metal reenforced gate to keep out others",
         "chamber", "Once a great room, now just a ruin",
         "great hall", "Connected to this entry chamber",
         "hall", "Connected to this entry chamber",
         "entrance", "Sitting off to the south of you",
         "main entrance", "Off to the south of you",
         "guard room", "A place were once guards stood in watch",
         "stain", "It looks to be dried blood",
         "gate", "A great wooden and metal reenforced door to keep out others",
         "wood", "Great timbers are now dried and splintered",
         "metal", "Large pieces were used to hold the wood in place for the door",
         "arrow", "Stuck in the gate's wood, it is of goblin make",
         "shaft", "Stuck in the gate's wood, it is of goblin make", 
         "doors", "These lay basically untouched aside from the oddly dried stain or stray arrow shaft"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh13.c", "north",
         "players/khrell/area/underways/undermdh16.c", "west",
         "players/khrell/area/underways/undermdh17.c", "east",
         "players/khrell/area/underways/undermdh18.c", "south"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
