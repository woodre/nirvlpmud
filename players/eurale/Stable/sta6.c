/*  Drygulch stable  */

#include "defs.h"
inherit "room/room";
object hand;

reset(arg) {

if(!present("bart")) {
  hand = clone_object(HAND);
  hand->set_name("bart");
  hand->set_short("Bart, a hired  hand");
  move_object(hand,TO); }
if(!present("slappy")) {
  hand = clone_object(HAND);
  hand->set_name("slappy");
  hand->set_short("a hand called Slappy");
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
	"/players/eurale/Stable/sta2.c","east",
});

}
