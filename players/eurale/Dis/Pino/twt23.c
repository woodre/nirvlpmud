#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("stromboli")) {
  move_object(clone_object("players/eurale/Dis/Pino/NPC/strom"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Gypsy Wagon";
long_desc =
	"  You climb aboard the wagon and find yourself in a cozy but \n"+
	"cramped area full of items to be sold.  There are bright, colored\n"+
	"cloth pieces hanging from the supporting framework and off to the \n"+
	"side you can see a crystal ball partially covered.\n";

items = ({
	"items","Alixers, pots and pans, anything of value",
	"pieces","Bright items used as part of the gypsy attire",
	"ball","A clear, glass orb for telling fortunes",
});

dest_dir = ({
	"players/eurale/Dis/Pino/twt22.c","out",
});

}
