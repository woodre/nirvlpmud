#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   The slums seem less oppressive here, and this area opens up to\n"+
"the north.  Still, the stench of unwashed skaven and fecal matter\n"+
"assails ones senses, leaving one breathless.  The walls loom far\n"+
"above, and no light can penetrate this gloom.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell unwashed skaven and fecal matter.\n");
   items = ({
         "walls", "They loom high above your head"});
   dest_dir = ({
         "players/khrell/area/skaven/ss1.c", "south",
         "players/khrell/area/skaven/ss6.c", "north"});
   return 1; }
