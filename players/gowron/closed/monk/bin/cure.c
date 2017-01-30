#include "../def.h"

main() {
	object flu;
	
	flu = present("flu", TP);
	if (!flu) {
 	   write("You are not sick you hypochondriac!\n");
	   return 1;
	}
	if (RANK < 2) {
           write("This is a rank 2 spell.\n");
	   return 1;
	}
	if (MYSP < 75) {
           write("You do not have enough spell points.\n");
	   return 1;
	}
	destruct(flu);
	TP->add_spell_point(-75);
	write("You have been cured.\n");
	return 1;
}

