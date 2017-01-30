#include <ansi.h>
#define NAME "Sparrow"
#define DEST "room/lanceroad4"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "castle"; }

short() {
    return;
	return HIW+"A "+HIC+"Beat Up"+HIW+" Truck"+HIC+"-"+HIW+"Bed Camper"+NORM;
}

long() {
    write(HIW+"This is a small camper that people normally mount in the bed of\n"
	     +"truck for fun-filled weekend excursion. This is no such camper.\n"
	     +"Stacks of cinder blocks support the camper and make it somewhat\n"
	     +"safe to enter. A small hole has been cut in the roof and a narrow\n"
		 +"stove pipe rises out from inside. A dog food bowl and water dish\n"
		 +"sit near the door and fresh canine paw prints litter the ground\n"
		 +"where not obscured by empty beer cans.\n"+NORM);
}

init() {
  add_action("enter", "enter");
}

enter(str) {
    if (!str || !str == "camper") {
	  return 0;
    }
	write("The door to the camper is locked.\n");
    return 1;
}

reset(arg) {
    string *drop;
	object *bwo_list;
    object ob, bwo, temp_ob;
    string room;
	if (arg)
	  return;
    move_object(this_object(), DEST);
}

is_castle(){return 1;}