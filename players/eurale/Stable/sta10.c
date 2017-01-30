/*  Drygulch stable  */

#include "defs.h"
inherit "room/room";
object hand;

reset(arg) {

if(!present("jack")) {
  hand = clone_object(HAND);
  hand->set_name("lester");
  hand->set_alias("bum");
  hand->set_short("Lester the bum");
  move_object(hand,TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  You are standing in one of the horse stalls.  There is hay \n"+
	"piled up for feed and rings on each side of the opening.  The \n"+
	"stall is clean and there is a large bucket in the corner.  A \n"+
	"beautiful horse is tethered to the stall wall. \n";

items = ({
	"rings","Metal rings mounted to the wooden sides of the stall \n"+
		"to tie the horses to",
	"bucket","A wooden bucket holding water",
	"horse","A large, jet-black gelding... beautiful",
});

dest_dir = ({
	"/players/eurale/Stable/sta2.c","west",
});

}
