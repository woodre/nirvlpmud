/*  Drygulch stable  */

#include "defs.h"
inherit "room/room";
object hand;

reset(arg) {

if(!present("chet")) {
  hand = clone_object(HAND);
  hand->set_name("chet");
  hand->set_short("hired hand named Chet");
  move_object(hand,TO); }
if(!present("louis")) {
  hand = clone_object(HAND);
  hand->set_name("louis");
  hand->set_short("Louis");
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
	"horse","A smooth and glossy pinto mare",
});

dest_dir = ({
	"/players/eurale/Stable/sta3.c","west",
});

}
