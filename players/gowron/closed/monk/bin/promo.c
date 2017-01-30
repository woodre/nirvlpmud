#include "../def.h"

main(arg) {
	object ob;
	string str;
	int lev;

	sscanf(arg, "%s %d", str, lev);
	
	ob = find_player(str);
	if (!ob) {
           write(str+" is not logged in right now.\n");
	   return 1;
	}
	if (!lev) {
           write("Usage promo <who> <what>\n");
	   return 1;
	}
	ROBE->set_rank(lev);
	lev;
	switch(lev) {
	    case 1: ROBE->set_gxp(1);
	    case 2: ROBE->set_gxp(20000);
	    case 3: ROBE->set_gxp(50000);
	    case 4: ROBE->set_gxp(120000);
	    case 5: ROBE->set_gxp(230000);
	    case 6: ROBE->set_gxp(550000);
	    case 7: ROBE->set_gxp(840000);
	    case 8: ROBE->set_gxp(1500000);
	    case 9: ROBE->set_gxp(2600000);
	    case 10: ROBE->set_gxp(3040000);
	}
	write("Promoting "+str+" to rank "+lev+"\n");
	return 1;
}

