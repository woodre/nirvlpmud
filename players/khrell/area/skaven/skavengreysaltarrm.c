#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIK+"Greyseer"+NORM+"]");
   set_long(
"   A carved altar dominates this room.  A great many candles cast\n"+
"a strange light dulling flame, making it hard to discern any other\n"+
"detail aside from the altar.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear quiet chittering chants from all about you.\n");
   add_smell("main", "You smell burnt offerings in the air.\n");
   items = ({
         "altar", "A large sacrifical altar splashed with fresh blood",
         "candle", "Large and lumpy you realise it's made from human fat",
         "candles", "Large and misshapen, they take in light instead of give it",
         "blood", "Clearly it was belonging to a human, as a skavens isn't so dark"});
   dest_dir = ({
         "players/khrell/area/skaven/skavengreyschamber.c", "out"});
   move_object(clone_object("/players/khrell/monster/skaven/verminlord.c"), this_object());
   return 1; }
