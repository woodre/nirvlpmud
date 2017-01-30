#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+YEL+"Pestilens"+NORM+"]");
   set_long(
"   The Clan Pestilen's monastery is quite literally the most foul and\n"+
"disgusting place mortal hands or paws could ever create.  It is a\n"+
"tribute to disease, rot and decay.  Bodies have been nailed to the\n"+
"wall in a decorative manner and left to putrefy.  A great many flies\n"+
"buzz about here and the crunch of maggots tell of the contents of the\n"+
"floor.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow");
   add_listen("main", "You hear buzzing of flies.\n");
   add_smell("main", "You smell the sickening sweet smell of decay.\n");
   items = ({
         "bodies", "Human, elven, dwarven, goblinoid and skaven corpses",
         "wall", "It's covered in the mortal remains of many beings",
         "flies", "They buzz around nearly choking you",
         "maggots", "Crunch crunch!  Definately not something to write home about"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenpestilenrectory.c", "south",
         "players/khrell/area/skaven/skavenpestilenaltar.c", "north",
         "players/khrell/area/skaven/skavenpestilenfoyer.c", "exit"});
   move_object(clone_object("/players/khrell/monster/skaven/plaguemonk3.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/plaguemonk2.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/plaguemonk1.c"), this_object());
   return 1; }
