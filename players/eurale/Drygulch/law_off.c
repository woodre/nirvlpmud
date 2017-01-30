/*  sherrif's office  */

#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("wyatt")) {
  move_object(clone_object("players/eurale/Drygulch/NPC/earp"),TO); }

  if(arg) return;
set_light(1);

short_desc = "Drygulch";
long_desc =
	"  You stand in the center of the sherrif's office of Drygulch. \n"+
	"There is a large desk, two windows looking out at the street as \n"+
	"it were, a chair, a wall cabinet and a small stove. \n";

items = ({
	"desk","A large wooden desk with drawers to hold documents and \n"+
		"wanted poster information",
	"windows","Barred windows looking out toward Drygulch",
	"chair","A wooden, straight-backed chair",
	"cabinet","A wooden gun cabinet with assorted weapons and bullets \n"+
		"and a secure door with a lock",
	"stove","A black, pot-bellied stove to provide warmth on cool \n"+
		"evenings and also a place to warm a pot of coffee",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs11.c","south",
});

}
