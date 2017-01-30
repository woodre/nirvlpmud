#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Glade of the Asrai"+NORM);
   set_long("This is the description.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/closed/glade/gr5.c", "south",
         "players/khrell/closed/glade/gr7.c", "north"});
   move_object(clone_object("/players/khrell/EX/mob.c"), this_object());
   return 1; }