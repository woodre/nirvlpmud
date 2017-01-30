#include "DEFS.h"
inherit "room/room";

reset(arg) {
if(!present("man")) {
  move_object(clone_object("players/eurale/Fiend/NPC/invisman"),TO); }
  if(arg) return;
set_light(1);

short_desc = "Fiendsville";
long_desc =
	"  This is the Fiendville Lab.  The smell of disinfectant is very\n"+
	"strong.  There are counters lining the walls with various pieces\n"+
	"of testing equipment.  Display cases reveal bottles of drugs and\n"+
	"body parts being preserved in some kind of liquid.  The floor\n"+
	"is polished tile... and very clean.  There is another room to\n"+
	"the south.\n";

items = ({
	"counters","Steel and unpainted for cleanliness",
	"equipment","An EKG machine, a heart monitor, blood cleanser",
	"drugs","Mainly surgical drugs and painkillers",
	"liquid","A slightly green and strong smelling liquid",
	"parts","A heart, some eyes, a partial lung, a brain",
});

dest_dir = ({
	"players/eurale/Fiend/mm7.c","out",
	"players/eurale/Fiend/mm32.c","south",
});

}

init() {
  ::init();
  add_action("south","south");
  TP->set_fight_area();
}

south() {
  if(present("man")) {
	write("Something keeps you from going south..\n");
	say("Something stops "+capitalize(TPRN)+" from going south..\n");
  return 1; }

  if(!present("man")) {
	TP->move_player("south#players/eurale/Fiend/mm32.c"); return 1; }
}
