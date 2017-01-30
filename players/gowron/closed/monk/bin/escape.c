#include "../def.h"

main() {
	if (RANK < 3) {
           LOW_RANK;
	   return 1;
	}
	if (MYSP < 40) {
           NO_SP;
	   return 1;
	}
	if (environment(TP)->realm() == "NT") {
           write("You cannot do that here.\n");
	   return 1;
	}
	write("You teleport back to the guild hall.\n");
	say(CME+" teleports back to the guild hall.\n");
	TP->move_player("away#players/gowron/closed/monk/new_mroom");
	TP->add_spell_point(-40);
	return 1;
}

