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
         "players/khrell/closed/glade/gr8.c", "south",
         "players/khrell/closed/glade/gr7.c", "north",
         "players/khrell/closed/glade/gr7.c", "east",
         "players/khrell/closed/glade/gr8.c", "west",
         "players/khrell/closed/glade/gr7.c", "northwest",
         "players/khrell/closed/glade/gr9.c", "northeast",
         "players/khrell/closed/glade/gr7.c", "southwest",
         "players/khrell/closed/glade/gr8.c", "southeast"});
   return 1; }