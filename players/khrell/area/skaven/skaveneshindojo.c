#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+HIK+" - Eshin"+NORM);
   set_long(
"   The main entry room of the assassin clan Eshin fills one with\n"+
"a sense of danger.  Dark shadows cling to the walls, and appear to\n"+
"move and shift with a life of their own.  Faded grass mats cover\n"+
"the floor and seem to muffle any sound made when treading upon\n"+
"them.\n");        
   set_light(-1);
   add_property("fight_area");
   add_listen("main", "You hear nothing.\n");
   add_smell("main", "You smell a faint scent of incense.\n");
   items = ({
         "shadows", "They seem to move and shift about as if watching you",
         "walls", "Dark shadows seem to cling to them",
         "mats", "Made from tightly woven grass",
         "floor", "It's covered by grass mats"});
   dest_dir = ({
         "players/khrell/area/skaven/skaveneshintrainrm.c", "north",
         "players/khrell/area/skaven/skaveneshinarena.c", "northeast",
         "players/khrell/area/skaven/ss8.c", "out"});
   move_object(clone_object("/players/khrell/monster/skaven/nightrun1.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/gutterrun.c"), this_object());
   return 1; }
