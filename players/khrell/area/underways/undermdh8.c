#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
This side hall has seen better days.  The siege has wrecked it, with looters\n\
having taken anything of value from here.  A side chamber sits off to the west\n\
and to the south is a large blasted hole in the wall.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "hole", "Blackened and cracked, as if some heavy explosives were used",
         "hall", "An addition ot the main antechamber",
         "chamber", "A now empty room, stripped clean by looters",
         "wall", "Blackened and covered in old soot",
         "soot", "The result from explosives leaving their mark on the wall's surface"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh6.c", "east",
         "players/khrell/area/underways/undermdh9.c", "west",
         "players/khrell/area/underways/undermdh10.c", "south"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
