#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak "+NORM+"["+MAG+"Moulder"+NORM+"]");
   set_long(
"  This room is all but empty except for a large hole in the floor.\n"+
"Dark shadows cling to the walls here and one could almost swear they\n"+
"were alive and moving as if watching.\n");
   set_light(0);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell all sorts of disgusting things.\n");
   dest_dir = ({"players/khrell/area/skaven2/rm1.c", "north",
                "players/khrell/area/skaven2/rmm1.c", "down"});
   move_object(clone_object("/players/khrell/area/skaven2/mobs/girat.c"), this_object());
   move_object(clone_object("/players/khrell/area/skaven2/mobs/girat.c"), this_object());
   move_object(clone_object("/players/khrell/area/skaven2/mobs/girat.c"), this_object());
   move_object(clone_object("/players/khrell/area/skaven2/mobs/girat.c"), this_object());
   return 1; }