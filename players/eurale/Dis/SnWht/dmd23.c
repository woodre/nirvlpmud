#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("doc")) {
  move_object(clone_object("players/eurale/Dis/SnWht/NPC/doc"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Woodland cottage";
long_desc =
	"  This is cottage kitchen.  There is a counter with a large bowl\n"+
	"and pitcher sitting on it.  A huge, pot-bellied stove takes up\n"+
	"most of the room.  There are pans hanging on the walls.\n";

items = ({
	"counter","A sturdy wood counter for preparing meals",
	"bowl","A carved wooden bowl, very large",
	"pitcher","A hollowed out wooden pitcher for liquids",
	"pans","Various sizes of cast iron cookware",
	"stove","A very large stove with lots of cooking space on the \n"+
		"surface and an oven to cook feasts",
});

dest_dir = ({
	"players/eurale/Dis/SnWht/dmd22.c","north",
	"players/eurale/Dis/SnWht/dmd21.c","west",
	"players/eurale/Dis/SnWht/dmd20.c","northwest",
});

}
