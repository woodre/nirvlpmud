#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("blacksmith")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/smithy"),TO); }

  if(arg) return;
set_light(1);

short_desc = "A Merchant Shop";
long_desc =
	"  This is the local blacksmith's shop.  It would be more correct\n"+
	"to call it a weaponsmith's shop.  There are various hammered\n"+
	"breastplates and helmets hanging on the walls.  A large furnace\n"+
	"sits against the rear wall and there is a bucket on the floor\n"+
	"near it.\n";

items = ({
	"breastplates","Hammered metal for best protection",
	"helmets","Metal helmets with flip-down face masks",
	"furnace","A deep, well-insulated furnace with a large bellows\n"+
		"to allow super-heating",
	"bucket","A deep, wooden bucket with quenching liquid",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh20.c","north",
});

}
