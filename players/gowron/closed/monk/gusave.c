#include "players/gowron/closed/monk/def.h"

cmd_gusave() {
	ROBE->save_me();
	write("Saving guild stats....\n");
	return 1;
}	
