/*  Drygulch stable  */

#define tp this_plaher()->query name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  You are standing in one of the horse stalls.  There is hay \n"+
	"piled up for feed and rings on each side of the opening.  The \n"+
	"stall is clean and there is a large bucket in the corner. \n";

items = ({
	"rings","Metal rings mounted to the wooden sides of the stall \n"+
		"to tie the horses to.",
	"bucket","A wooden bucket holding water.",
});

dest_dir = ({
	"/players/eurale/Stable/sta0.c","dir",
});

}
