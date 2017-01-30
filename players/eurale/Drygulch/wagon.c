/*  The healing wagon with 'Gabby' the seller  */

#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("gabby")) {
  move_object(clone_object("players/eurale/Drygulch/NPC/gabby"),TO); }
set_light(1);

short_desc = "A covered wagon";
long_desc =
	"  The inside of the wagon is neat and orderly and piled high with \n"+
	"boxes.  The canvas covering keeps the sun out and provides shade \n"+
	"in this inhospitable place.\n";

items = ({
	"boxes","The wooden boxes have the word 'heals' stenciled on them",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs7.c","out",
});

}
