#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   Widening slightly here the tunnel allows one to stand slightly\n"+
"less stooped over.  Small nicks and scratches dot along the walls\n"+
"and indicate unprofessional skill in the forming of this tunnel and\n"+
"is nothing more then a poorly made passage through solid rock. The\n"+ 
"tunnel continues to the north and south.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "tunnel", "It's long it's dark and it goes to the north and south",
         "passage", "It's long and dark and yes... it goes north and south.",
         "nicks", "A small marking from a digging tool",
         "scratches", "Apparently made from the claws of some sort of beast"});
   dest_dir = ({
         "players/khrell/area/skaven/under3.c", "north",
         "players/khrell/area/skaven/under5.c", "south"});
   return 1; }
