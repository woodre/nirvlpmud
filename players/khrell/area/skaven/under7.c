#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Underways"+NORM+" ("+HIW+"Tunnel"+NORM+")");
   set_long(
"   The ceiling here is only a few feet from the floor forcing you\n"+
"to nearly crawl on your hands and knees.  The floor is rough and\n"+
"sharp.  Small ammounts of warpstone have been hammered into the\n"+
"walls to provide scarse illumination.  To the north and south of\n"+
"of your current position is the seemingly endless tunnel.\n");
   set_light(0);
   add_property("no_fight");
   add_property("no_teleport");
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "ceiling", "You smack your head on it when yo uattempt to look at it",
         "floor", "Rough and uneven it scrapes your knees and hands",
         "warpstone", "It gives off a weak pale greenish glow"});
   dest_dir = ({
         "players/khrell/area/skaven/under6.c", "north",
         "players/khrell/area/skaven/under8.c", "south"});
   return 1; }
