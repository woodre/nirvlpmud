/* Upstairs Bedroom, Created <8/4/01> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Zercher Castle- Upstairs Bedroom";
  long_desc=
    "  The bedroom is decorated in delicate, dusty pink fabrics and lace. The\n"+
    "bed stands in the center of the room, draped in a thickly woven mosquito\n"+
    "cloth and covered with sensuous fabrics. An armoire stands against the\n"+
    "eastern wall, slightly ajar, and there is a window with ruffled pink drapes.\n"+
    "A screen with three panels blocks one corner of the room, with a silk\n"+
    "dress draped over the top. There is a very fine layer of dust covering\n"+
    "everything in this room.\n";
  items=({
    "fabrics",
    "The fabrics are a light, dusty pink in color",
    "lace",
    "Delicate made white lace stitched into a beautiful pattern",
    "bed",
    "The ironcast bed has a thick comforter and several pillows",
    "comforter",
    "The comforter is made of a thickly woven fabric to provide warmth",
    "pillows", 
    "The two pillows are decorated with embroidery and lace",
    "armoire", 
    "An oak armoire, standing approximately five feet tall",
    "window",
    "The drapes have been pulled shut and are blocking the view",
    "drapes", 
    "The thick drapes are trimmed with a white lace", 
    "screen", 
    "The ironcast screen has paper-thin white panels",
    "dress",
    "A silk dress, royal purple in color",
    "dust",
    "The dust seems to have collected recently", });
  dest_dir=({
    PATH+"hall3","south" });
}

void init() {
  ::init();

  add_action("search","search");
}
search(str) {
  if(!str) {
    write("You find nothing.\n");
  return 1;
 }
}
