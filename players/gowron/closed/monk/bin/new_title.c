#include "../def.h"

main(str) {
	if (!str) { 
	   write("You cannot set your title to NOTHING!\n");
	   return 1;
	}
	if (RANK < 4) {
	   LOW_RANK;
	   return 1;
	}
	if (MYSP < 10) {
           NO_SP;
	   return 1;
	}
	TP->set_title(str);
	write("You are now: "+CME+" "+str);
	TP->add_spell_point(-10);
	return 1;
}

