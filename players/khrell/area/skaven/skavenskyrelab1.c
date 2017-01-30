#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+HIW+"Skryre"+NORM+"]");
   set_long(
"   This is the lowest labratory of the tower.  Here is where a great\n"+
"many devices are drawn up and devised.  A few tables sit in a near\n"+
"triangular pattern in the middle of the room.  Parchments and drawn\n"+
"up lans lay sprawled over the tables surfaces.  Along the walls are\n"+
"a great number of bronze wires, occasionally flickering with dark\n"+
"sparks of energy.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "table", "Large and made out of splintered wooden planks",
         "tables", "Arranged in a triangular pattern, a symbolic sign of Skavendom",
         "parchment", "It is written in the illegible script of the Skaven",
         "parchments", "The writing is unreadable, but the drawings are clear indicators of plans",
         "wire", "It occasionally sparks with some unknown source of power",
         "wires", "They occasionally spark with some unknown source of power"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenskyrelair.c", "down",
         "players/khrell/area/skaven/skavenskyrelab2.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/warleng.c"), this_object());
   return 1; }
