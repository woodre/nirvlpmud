/*  Jurassic Park  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("dimetroden")) {
  move_object(clone_object("players/eurale/Park/NPC/dime"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Jurassic Park";
long_desc =
	"  You have entered a land of thick underbush and dense trees\n"+
	"that blocks out most of the sun.  The vegetation is very tall \n"+
	"and consists of huge ferns and very thick vines which fall from \n"+
	"high up in the trees.  The air is hot and humid and you can hear \n"+
	"the sound of huge animals all around you. \n";

items = ({
	"trees","The trees are very tall with thick growth at the top. \n"+
		"They provide protection and shelter",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"vines","Large, thick, rope-like stems of plants that climb the \n"+
		"trees and run along the ground",
	"underbrush","Thick growth that looks nearly impassible",
});

dest_dir = ({
	"players/eurale/Park/jp34.c","north",
	"players/eurale/Park/jp45.c","east",
	"players/eurale/Park/jp43.c","west",
});

}

init() {
  ::init();
  add_action("south","south");
}

south() {
if(present("dimetrodon")) {
  write("The dimetroden rams you as you make a move....\n");
  TP->heal_self(-(25 + random(20)));
  return 1; }
else {
  TP->move_player("underbrush#players/eurale/Park/jp54.c");
  return 1; }
}
