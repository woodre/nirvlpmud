/* Whack-A-Wiz Land- Path1. Created <8/30/00> by Jara */

#include "defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway through the clouds";
  long_desc="  A pathway parts through the delicate white clouds. The sky is a\n"+ 
    "brilliant pink, tinted with a bright purple, and there are mounds of\n"+
    "pastel colored dirt visible within the soft mist of clouds. A cluster\n"+
    "of round lollipops seems to grow from the dirt, and in the distance,\n"+
     "a large tower looms overhead.\n";
  items=({
    "tower",
    "A crystal tower that seems to change color at every angle",
    "cloud",
    "The delicate white clouds seem to shift and move with the breeze" });
  dest_dir=({ 
    PATH+"path2","north",
    PATH+"path8","east",
    PATH+"enter","south" });
}
