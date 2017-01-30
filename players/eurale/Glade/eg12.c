#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);
if(!present("ankheg")) {
  move_object(clone_object("players/eurale/Glade/NPC/ankheg"),TO); }

short_desc = HIG+"Enchanted Glade"+NORM;
long_desc =
 "  You've stepped out of the tall grass and find yourself standing\n"+
 "on a steep embankment that borders a rapidly flowing river.  The\n"+
 "river is frothy and an angry green color.  It seems to flow a ways\n"+
 "farther to the east and appears to disappear.  There is a worn and\n"+
 "broken sign stuck in the embankment near the drop-off.\n";

items = ({
  "embankment","Very steep, too steep to descend, leading right up to the\n"+
		"edge of the river",
  "river","A wide, raging river with swirling eddies.  With any luck\n"+
	  "one could probably dive from here and make it to the water\n"+
	  "but it would be close and very dangerous",
  "sign","A hand-painted sign, done long ago by the condition of it.\n"+
	"Maybe you could read it?",
});

dest_dir = ({
});

}

init() {
  ::init();
  add_action("search","search");
  add_action("north","north");
  add_action("south","south");
  add_action("east","east");
  add_action("west","west");
  add_action("read","read");
  add_action("dive","dive");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

north() {
  TP->move_player("into the grass#players/eurale/Glade/eg11.c");
  return 1; }
south() {
  write("You walk over to the edge of the embankment... some of it\n"+
	"crumbles away and rolls into the water.\n");
  return 1; }
east() {
  TP->move_player("into the grass#players/eurale/Glade/eg13.c");
  return 1; }
west() {
  TP->move_player("into the grass#players/eurale/Glade/eg7.c");
  return 1; }

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") {
  write("The make-shift sign is faded from the sun and elements but\n"+
	"it appears to say 'D..nge.o.s .iver - do n.t ent.r!'\n");
  return 1; }
}

dive(str) {
if(!str) { write("Dive?  Dive where?\n"); return 1; }
if(str == "river") {
  write("You take a short run and dive towards the raging river...\n"+
	"You stretch out your arms and hope that the water below will\n"+
	"be deep enough......\n");
  TP->move_player("diving into the river#players/eurale/Glade/river.c");
  return 1; }
}
