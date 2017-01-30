#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIY+"Commons"+NORM+"]");
   set_long(
"   This a relatively clean looking area.  It still smells with the\n"+
"stink of unwashed skaven.  Countless eyes stare at you from a great\n"+
"many cracks and holes in the walls.  Off to the side is a noticeable\n"+
"sign that stands out from the rest of the area.\n"); 
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell the stink of unwashed skaven.\n");
   items = ({
         "eyes", "They glare at you with hatred",
         "crack", "A split in the wall",
         "cracks", "A number of splits in the wall",
         "hole", "A very small opening in the wall",
         "holes", "Alot of many small holes in the wall",
         "sign", ""+HIR+"["+HIK+"The Rat Hole"+HIR+"]"+NORM+""});
   dest_dir = ({
         "players/khrell/area/skaven/ss6.c", "west",
         "players/khrell/area/skaven/ratbar.c", "in"});
   return 1; }
