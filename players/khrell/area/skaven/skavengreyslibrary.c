#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIK+"Greyseer"+NORM+"]");
   set_long(
"   This is the library of the Greyseer of Fester Peak.  Many large\n"+
"and imposing bookshelves lay against the walls.  A few well placed\n"+
"candles cast a gloomy light through the room, giving the shadows\n"+
"sinister movements.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell burnt fat and traces of warpstone.\n");
   items = ({
         "bookshelf", "It's large and it holds books",
         "bookshelves", "Large and imposing, they hold alot of skaven books",
         "books", "Written in the skaven language and enchanted with magic they are impossible to read",
         "candles", "Misshapen, they sputter and give off light to read by",
         "shadows", "Created from the candlelight, they are harmless"});
   dest_dir = ({
         "players/khrell/area/skaven/skavengreyschamber.c", "out"});
   move_object(clone_object("/players/khrell/monster/skaven/kwelenseer.c"), this_object());
   return 1; }
