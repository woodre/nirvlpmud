/*  Drygulch stable  */

#include "defs.h"
inherit "room/room";
object hand;

reset(arg) {

if(!present("drak")) {
  hand = clone_object(HAND);
  hand->set_name("drak");
  hand->set_short("Drak, a hired hand");
  move_object(hand,TO); }
if(!present("johnny")) {
  hand = clone_object(HAND);
  hand->set_name("johnny");
  hand->set_short("hired hand called Johnny");
  move_object(hand,TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Stable";
long_desc =
	"  You are standing in one of the horse stalls.  There is hay \n"+
	"piled up for feed and rings on each side of the opening.  The \n"+
	"stall is clean and there is a large bucket in the corner. \n";

items = ({
	"rings","Metal rings mounted to the wooden sides of the stall \n"+
		"to tie the horses to",
	"bucket","A wooden bucket holding water",
});

dest_dir = ({
	"/players/eurale/Stable/sta4.c","west",
});

}
