#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"("+HIG+"Mines"+NORM+")");
   set_long(
"   Rivers of the thick sludge ooze downward.  Foul odors waft through\n"+
"the stiff air here.  Here, as above, the sludge clings to just about\n"+
"everything it comes in contact with.  At one end of this passage the\n"+
"sludge seeps into an enormous hole.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell foul, stomach churning odors.\n");
   items = ({
         "sludge", "Debris and other toxic material left overs from refinement processess",
         "hole", "It's large, and the sludge seems to go down into it",
         "passage", "The narrow area your currently in"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarppit1.c", "up",
         "players/khrell/area/skaven/skavenwarppit4.c", "down"});
   move_object(clone_object("/players/khrell/monster/skaven/sludgespawn.c"), this_object());
   return 1; }
