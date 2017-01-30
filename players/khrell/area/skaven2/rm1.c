#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+MAG+"Moulder"+NORM+"]");
   set_long("\
   This crude shaft was mined from solid granite rock.  The walls all\n\
bear telltale signs of shoddy work; uneven cuts, chips, and gouges.\n\
Several exits are easily accessable from here leading deeper into\n\
the holdings of Clan Moulder.\n");
   
   set_light(0);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell unwashed skaven and other bestial bodies.\n");
   items = ({
         "shaft", "Crudely hewn from solid granite rock",
         "cuts", "Signs that this place was mined",
         "chips", "Small fragments of rock",
         "gouges", "Rough looking and jagged holes in the stone"});
   dest_dir = ({
         "players/khrell/area/skaven/ss20.c", "up",
         "players/khrell/area/skaven2/rm2.c", "west",
         "players/khrell/area/skaven2/rm3.c", "east",
         "players/khrell/area/skaven2/rm4.c", "south",
         "players/khrell/area/skaven2/rm5.c", "north"});
   move_object(clone_object("/players/khrell/area/skaven2/mobs/clanrat.c"), this_object());
   move_object(clone_object("/players/khrell/area/skaven2/mobs/girat.c"), this_object());
   move_object(clone_object("/players/khrell/area/skaven2/mobs/slave.c"), this_object());
   return 1; }
