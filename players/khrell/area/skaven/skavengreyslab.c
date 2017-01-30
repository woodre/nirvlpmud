#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIK+"Greyseer"+NORM+"]");
   set_long(
"   This laboratory reeks of evil.  All sorts of experiments have been\n"+
"done here.  An examination table dominates the center of this room.\n"+
"Against the walls are various surgical implements, all of which are \n"+
"stained with blood.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "table", "It's rectangular with shackles for wrists and ankles",
         "laboratory", "It's filled with various different items used in experiments",
         "items", "Various implements used in experiments",
         "implements", "Scalpels, bone-saws and other items used for cutting open beings",
         "blood", "It's dark and dried but somewhat still fresh"});
   dest_dir = ({
         "players/khrell/area/skaven/skavengreyschamber.c", "out"});
   return 1; }
