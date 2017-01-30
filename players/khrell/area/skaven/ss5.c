#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   The slums here feel give you a sense of hoplessness, but also\n"+
"send a chill down ones spine.  The shadows here appear almost as\n"+
"a tangible thing, and even move slightly of their own accord.  To\n"+
"the north, the shadows are like a large gaping maw looking for the\n"+
"next meal.\n");
   set_light(-1);
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "shadow", "It seems to move away from your gaze",
         "slums", "The area of the down-trodden of Skaven society",
         "shadows", "They move out of the corners of your eyes"});
   dest_dir = ({
         "players/khrell/area/skaven/ss2.c", "east",
         "players/khrell/area/skaven/ss7.c", "north"});
   return 1; }
