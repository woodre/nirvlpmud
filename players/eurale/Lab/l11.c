#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("bugbear")) {
  move_object(clone_object("/players/eurale/Lab/NPC/bugbear.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  Soft, tan sandstone acts as the walls to this very narrow room.\n"+
  "The jagged crack through the stone widens just enough here to turn\n"+
  "around and bend down.  Small discolored scraps litter the floor the\n"+
  "entire length of the opening.\n";

items = ({
  "sandstone","Tan, crumbling stone",
  "crack","A narrow opening you can probably slide through to get out",
  "stone","Solf-looking tan stone",
  "scraps","They appear to be decomposing pieces of meat",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("slide","slide");
}

slide(str) {
if(!str) { write("Slide?\n"); return 1; }
if(str == "crack" || str == "opening") {
  write("You slide through the narrow "+str+".\n");
  TP->move_player("through the crack#players/eurale/Lab/l10.c");
  return 1; }
}
