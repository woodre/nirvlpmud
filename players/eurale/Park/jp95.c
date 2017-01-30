/*  Jurassic Park  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("raptor 1")) {
  move_object(clone_object("players/eurale/Park/NPC/raptor1"),TO); }
if(!present("raptor 2")) {
  move_object(clone_object("players/eurale/Park/NPC/raptor2"),TO); }

  if(arg) return;
set_light(0);

short_desc = "Jurassic Park";
long_desc =
	"  You have entered a land covered with a dense growth of trees \n"+
	"that blocks out most of the sun.  The vegetation is very tall \n"+
	"and consists of huge ferns and very thick vines which fall from \n"+
	"high up in the trees.  The air is hot and humid and you can hear \n"+
	"the sound of huge animals all around you.\n"+
	"There is a small sign stuck in the ground.\n";

items = ({
	"sign","An 'Exit' sign pointing east",
	"trees","The trees are very tall with thick growth at the top. \n"+
		"They provide protection and shelter",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"vines","Large, thick, rope-like stems of plants that climb the \n"+
		"trees and run along the ground",
});

dest_dir = ({
	"players/eurale/Park/jp85.c","north",
	"players/eurale/Park/jp96.c","east",
	"players/eurale/Park/jp94.c","west",
});

}

