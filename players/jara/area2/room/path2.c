/* Whack-A-Wiz Land- Path2. Created <8/30/00> by Jara */

#include "defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway through the clouds";
  long_desc="  A pathway parts through the delicate white clouds. The sky is a\n"+ 
    "brilliant pink, tinted with a bright purple, and there are mounds of\n"+
    "pastel colored dirt visible within the soft mist of clouds. There are\n"+
    "rows of tiny blue flowers bordering each side of a dirt pathway leading\n"+
    "east to a garden clearing.\n";
  items=({
    "tower",
    "A crystal tower that seems to change color at every angle",
    "clouds",
    "The delicate white clouds seem to shift and move with the breeze" });
  dest_dir=({ 
    PATH+"path3","north",
    PATH+"ccandy","east",
    PATH+"path1","south" });
}
