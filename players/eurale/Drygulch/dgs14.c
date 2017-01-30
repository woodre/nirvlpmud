#define tp this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  The road curves off to the the northwest from here toward the \n"+
	"Indian camp.  Back to the east is the main portion of Drygulch \n"+
	"with the hotel and saloon.  The tumbleweeds have accumulated \n"+
	"here making a kind of natural thicket.\n";

items = ({
	"camp","You can just make out the sillouettes of teepees off in \n"+
		"the distance",
	"tumbleweeds","Rolling brush that seems to have piled up to the\n"+
		      "north of the trail.  It almost looks as if one\n"+
		      "could push thier way into them",
	"thicket","Lots of tumbleweeds tangled together",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs1.c","east",
	"/players/eurale/Drygulch/dgs15.c","northwest",
});

}

init() {
  ::init();
  add_action("push","push");
}

push(str) {
if(!str) { write("Push?\n"); return 1; }
if(str == "tumbleweeds" || str == "north") {
  tp->move_player("into the tumbleweeds#players/eurale/Drygulch/dgs16.c");
/*
  write("The tumbleweeds seem to be too thick to enter at this time.\n");
*/
  return 1; }
}
