#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+CYN+"Temple Gates"+NORM+"]");
   set_long(
"   This is the large imposing gates to the skavens' temple, dedicated\n"+
"to their fell deity, the Great Horned Rat, or the Horned God.  The\n"+
"massive doors are forged of warpstone and mighty metal alloys to give\n"+
"it strength.  Dire runes have been stamped on its surface and flicker\n"+
"with the balefires of evil magics.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing.\n");
   items = ({
         "gates", "They are large and keep anyone from entering",
         "templar", "The central place of worship for the skaven",
         "doors", "They are large and keep anyone from entering",
         "runes", "They hurt your eyes just to look at them"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenhallway3.c", "south"});
   return 1; }
