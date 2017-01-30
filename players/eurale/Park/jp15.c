/*  Jurassic Park  */

#define tp this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Jurassic Park";
long_desc =
	"  You have entered a land covered with a dense growth of trees \n"+
	"that blocks out most of the sun.  The vegetation is very tall \n"+
	"and consists of huge ferns and very thick vines which fall from \n"+
	"high up in the trees.  The air is hot and humid and you can hear \n"+
	"the sound of huge animals all around you.  The area seems to be \n"+
	"quite hilly as well. \n";

items = ({
	"trees","The trees are very tall with thick growth at the top. \n"+
		"They profice protection and shelter",
 	"ferns","Shrubby, nonflowering plants with large stems and huge \n"+
		"fronds that reproduce by spores instead of seeds",
	"vines","Large, thick, rope-like stems of plants that climb the \n"+
		"trees and run along the ground",
});

dest_dir = ({
	"players/eurale/Park/jp5.c","north",
	"players/eurale/Park/jp6.c","northeast",
	"players/eurale/Park/jp24.c","southwest",
	"players/eurale/Park/jp14.c","west",
	"players/eurale/Park/jp4.c","northwest",
});

}

realm() { return "NT"; }
