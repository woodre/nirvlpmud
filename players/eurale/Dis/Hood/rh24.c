#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("baker")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/baker"),TO); }

  if(arg) return;
set_light(1);

short_desc = "A Merchant Shop";
long_desc =
	"  Ahhhhh... the smell of fresh bread!  This is one of the local\n"+
	"peasant bakeries.  There is a table with various breads and \n"+
	"pastries for sale.  A large, open stone oven takes up most of\n"+
	"space.  There is a long wooden paddle leaning against the side\n"+
	"of the oven.\n";

items = ({
	"table","A large wooden table",
	"breads","Rye, wheat and pumpernickel... all warm and aromatic",
	"pastries","Twists and fruit-filled",
	"oven","A stone, wood-burning oven",
	"paddle","A long wooden paddle for placing items in the oven",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh20.c","west",
});

}
