#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
This roughly dug room is obivously not the work of goblins.  Alchemical burn\n\
marks ring the edges of the room near the exits.  The stone here appears to \n\
have been completely melted by some unknown source of great heat.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "burns", "Residue of some great fire",
         "burn", "Residue of a great fire",
         "marks", "Scorched burned areas from fire",
         "mark", "A scorched burned area from fire",
         "room", "Flame has destroyed anything of note in here",
         "stone", "Obivously this was melted by some massive ammounts of heat long ago"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh8.c", "north",
         "players/khrell/area/underways/undermdh11.c", "east"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
