#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
if(!present("eyewing")) {
move_object(clone_object("/players/eurale/Keep/NPC/eyewing"),TO); }
  if(arg) return;
set_light(0);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You slowly stand erect and find yourself in a small, black\n"+
	"pocket in the stone, left there by rocks that have broken \n"+
	"away.  It is a very confining space with a very peculiar odor.\n";

dest_dir = ({
	"players/eurale/Keep/k32.c","kneel",
});

}

init() {
  ::init();
  add_action("smell","smell");
}

smell(str) {
if(!str) { write("Trying to smell something?\n"); return 1; }
if(str == "odor" || str == "peculiar odor") {
  write("You sniff the air and the acidic smell scorches the sensitive\n"+
	"tissues of your nose and mouth.\n");
  TP->heal_self(-(15 + random(20)));
  return 1; }
}
