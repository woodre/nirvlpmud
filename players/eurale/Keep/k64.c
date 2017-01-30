#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("dragon")) {
move_object(clone_object("players/eurale/Keep/NPC/amphi_dragon"),TO); }
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have been sucked down through the murky water and are\n"+
	"now at the bottom of a cave, neatly hidden in the muck on the\n"+
	"bottom of the swamp floor.  You can hardly see through the dark\n"+
	"swirling water but......\n";

items = ({
});

dest_dir = ({
	"players/eurale/Keep/k43.c","swim",
});

}

init() {
  ::init();
  add_action("swim","swim");
}

swim() {
if(present("amphidragon")) {
  write("A strange suction prevents you from swimming up... \n"+
        "    and you're beginning to run out of air....\n");
  say(capitalize(TPRN)+" is not allowed to swim away by an unseen force...\n");
  TP->heal_self(-random(25));
  return 1; }
else {
  TP->move_player("swimming#players/eurale/Keep/k43.c");
  return 1; }
}
