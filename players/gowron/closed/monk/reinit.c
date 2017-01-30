#include "players/gowron/closed/monk/def.h"

cmd_reinit() {
	ROBE->init();
	write("Updating your commands...\n");
	return 1;
}

