#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Cave"+NORM+")");
   set_long("\
   This cave appears to be an exit from the vast Underways, though for the most\n\
part it is unremarkable from any other cave, this one is the lair of something\n\
quite big.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   dest_dir = ({
         "players/khrell/area/underways/under18.c", "down",
         "players/khrell/area/chaosforest/rm2.c", "out"});
   move_object(clone_object("/players/khrell/area/chaosforest/mob/gragnarok.c"), this_object());
   return 1; }
