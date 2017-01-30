#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("jim")) {
  move_object(clone_object("players/eurale/Hotel/NPC/bridger"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch Hotel parlor";
long_desc =
	"  This is the main parlor of the hotel.  Guests come here to \n"+
	"socialize and relax.  There is a large couch, a chair and \n"+
	"hanging from the ceiling is a huge chandelier.  The windows \n"+
	"that make up most of the wall space provide lots of light and \n"+
	"and a great view of the town and the mountains off to the \n"+
	"southwest. \n";

items = ({
	"couch","A large, long, stuffed couch that is somewhat threadbare",
	"chair","A stuffed chair that matches the couch",
	"chandelier","An ornate, cut-glass fixture that was probably \n"+
		"purchased in Europe by one of the wealthier guests",
});

dest_dir = ({
	"/players/eurale/Hotel/dgh2.c","east",
});

}
