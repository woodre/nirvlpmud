#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+HIW+"Skryre"+NORM+"]");
   set_long(
"   The air here has an electric tinge to it, causing the hairs on your\n"+
"body stand on end.  The faint aroma of burnt metal hangs in the air\n"+
"which does nothing to improve its quality.  To the west is a path that\n"+
"leads back to the town center, and to the east leads deeper into Clan\n"+ 
"Skryre's holdings.\n");      
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell a faint aroma of burnt metal.\n");
   items = ({
         "path", "It runs east and west"});
   dest_dir = ({
         "players/khrell/area/skaven/ss13.c", "west",
         "players/khrell/area/skaven/ss15.c", "east"});
   return 1; }
