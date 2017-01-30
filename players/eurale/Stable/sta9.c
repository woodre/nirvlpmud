/*  Drygulch stable  */

#include "defs.h"
inherit "room/room";
object hand;

reset(arg) {

if(!present("bret")) {
  hand = clone_object(HAND);
  hand->set_name("bret");
  hand->set_short("Bret");
  move_object(hand,TO); }
if(!present("roy")) {
  hand = clone_object(HAND);
  hand->set_name("roy");
  hand->set_short("drifter named Roy");
  hand->set_alias("drifter");
  move_object(hand,TO); }
if(!present("cookie")) {
  hand = clone_object(HAND);
  hand->set_name("cookie");
  hand->set_alias("cowboy");
  hand->set_short("Cookie, the cowboy");
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
	"/players/eurale/Stable/sta1.c","west",
});

}
