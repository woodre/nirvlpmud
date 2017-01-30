#include "../def.h"

main(str) {
	write("Turning your mchan "+str+"\n");
	if (str == "on") 
           ROBE->set_muffle(0);
	else
	   ROBE->set_muffle(1);
	return 1;
}

