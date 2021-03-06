/*  Jurassic Park  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("triceratops")) {
move_object(clone_object("players/eurale/Park/NPC/tri"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Jurassic Park";
long_desc =
	"  You have entered a land covered with a dense growth of trees \n"+
	"that blocks out most of the sun.  The vegetation is very tall \n"+
	"and consists of huge ferns and very thick vines which fall from \n"+
	"high up in the trees.  The air is hot and humid and you can hear \n"+
	"the sound of huge animals all around you.  There is a large\n"+
	"hill just off to the west with a large, dark hole dug into the\n"+
	"side of it.\n";

items = ({
	"trees","The trees are very tall with thick growth at the top. \n"+
		"They provide protection and shelter",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"vines","Large, thick, rope-like stems of plants that climb the \n"+
		"trees and run along the ground",
	"hole","A large cave type hole.  Maybe you could enter it",
	"hill","A large pile of dirt, well covered by vegetation",
});

dest_dir = ({
	"players/eurale/Park/jp29.c","east",
	"players/eurale/Park/jp38.c","south",
});

}

init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
if(present("triceratops")) {
  write("The big horned monster stops you from going that way.\n");
  return 1; }
if(!str || str == "hole") {
  TP->move_player("into the hole#players/eurale/Park/jp27.c");
  return 1; }
}
