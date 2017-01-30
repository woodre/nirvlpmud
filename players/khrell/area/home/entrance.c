#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIW+"Entrance"+NORM);
   set_long("\
   This is the elegant entrance area to the elegant and ancient dwelling\n\
of the wizard Khrell and his wife Aingeal.  It has a simple layout that \n\
allows one a measure of comfort without being too gaudy or flashy.\n");    
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/workroom.c", "south",
         "players/khrell/area/home/testlab.c", "east",
         "players/khrell/area/home/grove.c", "west"});
   return 1; }
