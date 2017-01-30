#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+HIK+" - Eshin"+NORM);
   set_long(
"   This is where Clan Eshin trains it's adepts in the arts of stealth\n"+
"and assasination.  Various dummies lay against the walls, each one\n"+
"has vital spots marked out and labeled.  The occasional splatter of\n"+
"blood shows that not all targets are the dummies in here.\n");    
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "dummies", "Various sized and shaped mannequins, stuffed with straw and crudely repaired",
         "wall", "A simple yet sturdy build of wood with supports",
         "blood", "At one time this obivously came from a living thing"});
   dest_dir = ({
         "players/khrell/area/skaven/skaveneshindojo.c", "south"});
   move_object(clone_object("/players/khrell/monster/skaven/nightrun2.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/nightrun1.c"), this_object());
   return 1; }
