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
         "players/khrell/closed/glade/gr20.c", "south",
         "players/khrell/closed/glade/gr13.c", "north",
         "players/khrell/closed/glade/gr20.c", "east",
         "players/khrell/closed/glade/gr19.c", "west",
         "players/khrell/closed/glade/gr16.c", "northwest",
         "players/khrell/closed/glade/gr15.c", "northeast",
         "players/khrell/closed/glade/gr19.c", "southwest",
         "players/khrell/closed/glade/gr20.c", "southeast"});
   move_object(clone_object("/players/khrell/EX/mob.c"), this_object());
   move_object(clone_object("/players/khrell/EX/mob.c"), this_object());
   return 1; }