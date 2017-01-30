/*  Eurale's time warp  */

#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
/* wocket moved mosnter clone to above if(arg) return; so it would respawn 08/23/2003 */ 
if(!present("sedjak")) {
move_object(clone_object("players/eurale/NPC/sedjak"),TO); }
  if(arg) return;
set_light(1);

short_desc = "Bartering Shack";
long_desc =
  "This small shack has a large trunk sitting against the back wall.\n"+
  "The wooden walls have cracks between the boards which let both light\n"+
  "and air in and the dirt floor is clean and smooth from the traffic\n"+
  "of many adventurers.  A wooden sign hangs on rear wall.\n";

items = ({
  "sign","An irregular shaped sign with hand lettering",
  "trunk","A large, domed-top trunk that stores all the merchant's "+
          "items for future sales",
  "walls","Thin boards lightly tacked together and easily disassembled",
  "floor","Smooth dark earth, recently swept",
  "cracks","Spaces between the boards from a poor fit",
});

dest_dir = ({
  "/players/eurale/RMS/titles","east",
});

}

realm() { return "NM"; }

init() {
  ::init();
  add_action("Read","read");
}

Read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign" || str == "lettering") { write(
  "Willing to barter for items of value....\n"+
  "   Fair prices and honest dealings for any and all...\n"+
  "                           Sedjak\n");
  return 1; }
}
