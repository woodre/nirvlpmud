#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Cave"+NORM+")");
   set_long("This is the description.\n");
   set_light(0);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/closed/glade/gladerm2.c", "descend",
         "players/khrell/closed/glade/gr4.c", "out"});
   return 1; }