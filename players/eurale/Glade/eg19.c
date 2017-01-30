#include "defs.h"
inherit "room/room";
int monster;

reset(arg) {
  if(arg) return;
set_light(1);
monster = 1;

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
  "  You wander along what appears to be a path and down a short slope.\n"+
  "The broken sunlight provides ample light for you to see and there is\n"+
  "a delicious smell of something cooking coming from somewhere nearby.\n"+
  "The fallen leaves provide almost a carpet and the slight breeze you\n"+
  "feel makes this a wonderful place to travel through.\n";

items = ({
  "path","A break through the underbrush traveled by animals",
  "slope","A gentle downward grade",
  "sunlight","Beams filtering down through the canopy",
  "leaves","Moist, rotting leaves from seasons passed",
});

dest_dir = ({
  "players/eurale/Glade/eg20.c","east",
  "players/eurale/Glade/eg18.c","west",
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("west","west");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

west() {
if(monster == 1) {
  write("As you start up the hill, a noise behind you catches your\n"+
	"attention....it's the sound of running on feet on the fallen\n"+
	"leaves.\n");
  move_object(clone_object("players/eurale/Glade/NPC/shaala"),TO);
  monster = 0;
  return 1; }
else {
  TP->move_player("up the hill#players/eurale/Glade/eg18.c");
  return 1; }
}
