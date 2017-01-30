/* Whack-A-Wiz Land- Garden. Created <8/30/00> by Jara */

#include "defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc=HIY+"Whack"+HIW+"-"+HIY+"A"+HIW+"-"+HIY+"Wiz Land"+HIW+": Garden Clearing"+NORM;
  long_desc="  The grass within the clearing grows a deep shade of blue. A flowerbed\n"+
    "lines the clearing, with several flowering bushes and decorative pieces\n"+
    "wood and stones. There is a bench near a beautiful rose tree near the\n"+
    "rear of the garden, and a songbird is sitting in the tree just above it.\n"+
    "A vendor has parked her cart here.\n";
    items=({
    "grass",
    "The thick blades of blue grass are well-trimmed and appear healthy",
    "bench",
    "A stone bench, made of a light stone and carved with beautifully polished\n"+
    "symbols",
    "symbols",
    "The symbols of a lion have been carved on both legs of the bench" });
  dest_dir=({ 
    PATH+"path2","west" });
}
