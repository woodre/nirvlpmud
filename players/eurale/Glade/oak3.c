#include "defs.h"
inherit "room/room";

reset(arg) {
/* moved above if(arg) return by wocket so she will respawn.  08/21/23 */
if(!present("madame rue")) {
  move_object(clone_object("players/eurale/Glade/NPC/rue"),TO); }

  if(arg) return;
set_light(1);

short_desc = "A large tree";
long_desc =
  "  This cozy, hollowed out room is full of strange aromas.  Cut into\n"+
  "the wood of the walls are shallow shelves with bottles and piles of\n"+
  "strange ingredients sitting on them.  There is a mat of pine boughs\n"+
  "spread on the rough floor.\n";

items = ({
  "walls","Tree trunk, roughly cut away",
  "shelves","Small indentations in the wood to store items",
  "bottles","Small bottles with unidentifiable items inside",
  "piles","Brown and black piles of herbs and other unknown substances",
  "ingredients","Ground-up items resembling colored flour",
  "mat","A comfortable cushion for sleeping",
  "boughs","Soft branches from conifurous trees",
});

dest_dir = ({
  "players/eurale/Glade/oak2.c","out",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search","search");
  add_action("smell","smell");
}

search(str) {
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing of interest.\n");
return 1;
}

smell(str) {
if(!str) { write("Smell what?\n"); return 1; }
if(str == "aromas") {
  write("As you breathe in, a sickly sweet smell assaults your senses.\n"+
	"Mixed in with the 'strange brew' smell is the scent of pine.\n");
  return 1; }
}
