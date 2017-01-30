#include "std.h"

object skeleton;

extra_reset() {
    object treasure;
    if (!skeleton || !living(skeleton)) {
	skeleton = clone_object("obj/monster");
	call_other(skeleton, "set_name", "skeleton");
	call_other(skeleton, "set_alias", "undead");
	call_other(skeleton, "set_level", 8);
        call_other(skeleton, "set_hp", 70);
	call_other(skeleton, "set_short", "A skeleton");
	call_other(skeleton, "set_wc", 7);
	call_other(skeleton, "set_ac", 5);
	call_other(skeleton, "set_al", -200);
	call_other(skeleton, "set_aggressive", 1);
	move_object(skeleton, this_object());
	treasure = clone_object("obj/treasure");
	call_other(treasure, "set_id", "ring");
	call_other(treasure, "set_alias", "gold ring");
	call_other(treasure, "set_short", "A gold ring");
	call_other(treasure, "set_weight", 1);
	call_other(treasure, "set_value", 200);
	move_object(treasure, skeleton);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

TWO_EXIT("players/deathmonger/CASTLE/fortress/entrance","south",
         "players/deathmonger/CASTLE/fortress/east_hall2","north",
         "More skeletons",
         "You seem to have found some more skeletons guarding the fortress\n"+
         "perimeter.  They hate living people, so they'll try to change you.\n",
1)
