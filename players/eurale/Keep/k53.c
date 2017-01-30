#include "/players/eurale/closed/ansi.h"
#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD+"The Keep"+NORM;
long_desc =
	"  You have wandered through the trees and worked your way up a\n"+
	"small hill.  The area seems to be much more hilly in this part\n"+
	"of the canyon.  The trees are much thinner and the grass is\n"+
	"thicker and taller... a good place for an ambush.\n";

items = ({
	"hills","Gently rolling mounds",
	"trees","Short, green, and leafy",
	"grass","Waist high and generally yellowish",
});

dest_dir = ({
	"players/eurale/Keep/k51.c","north",
	"players/eurale/Keep/k56.c","west",
});

}
