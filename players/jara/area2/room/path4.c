/* Whack-A-Wiz Land- Path4. Created <8/30/00> by Jara */

#include "defs.h"
#include "/players/jara/misc/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A pathway through the clouds";
  long_desc="  A pathway parts through the delicate white clouds. The sky is a\n"+ 
    "brilliant pink, tinted with a bright purple, and there are mounds of\n"+
    "pastel colored dirt visible within the soft mist of clouds. Just off the\n"+
    "pathway to the northwest, rows of red bulbs light a path to a magnificant\n"+     "rollercoaster. The tower is just to the northeast of here.\n";
  items=({
    "tower",
    "A crystal tower that seems to change color at every angle",
    "clouds",
    "The delicate white clouds seem to shift and move with the breeze" });
  dest_dir=({ 
    PATH+"path5","northeast",
    PATH+"menter","northwest",
    PATH+"path3","south" });
}
