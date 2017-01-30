/*  Jurassic Park  */

#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Jurassic Park";
long_desc =
	"  You have entered a land of thick underbrush and dense trees\n"+
	"that blocks out most of the sun.  The vegetation is very tall \n"+
	"and consists of huge ferns and very thick vines which fall from \n"+
	"high up in the trees.  The air is hot and humid and you can hear \n"+
	"the sound of huge animals all around you.  The deep ravine to \n"+
	"the north makes passage that way almost impossible.\n";

items = ({
	"underbrush","Thick growth that looks nearly impassible",
	"trees","The trees are very tall with thick growth at the top. \n"+
		"They provide protection and shelter",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"vines","Large, thick, rope-like stems of plants that climb the \n"+
		"trees and run along the ground",
});

dest_dir = ({
	"players/eurale/Park/jp58.c","east",
	"players/eurale/Park/jp67.c","south",
});

}

init() {
  ::init();
  add_action("west","west");
}

west() {
  tp->move_player("underbrush#players/eurale/Park/jp56.c"); return 1; }
