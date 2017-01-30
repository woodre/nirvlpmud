#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	int air, earth, fire, water, total;
	string title;
	
	air = (int)PO->query_AIR();
	earth = (int)PO->query_EARTH();
	fire = (int)PO->query_FIRE();
	water = (int)PO->query_WATER();
	
	total = air + earth + fire + water;
	
	if(PO->query_elder())
	{
		total = 29;
	}
	
	if(PO->query_gwiz())
	{
		total = 30;
	}
	
	switch(total)
	{
		case 30: title = ", Guild Wizard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM; break;
		case 29: title = ", Chosen "+HIK+"Elder"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM; break;
		case 25..28:
		title = ", "+HIW+"Ancient Master"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM; break;
		case 18..24:
		title = ", "+HIW+"Grand Master"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM; break;
		case 13..17:
		title = ", "+HIW+"Apprentice"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM; break;
		case 8..12:
		title = ", "+HIW+"Novice"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM; break;
		default:
		title = ", "+HIW+"Initiate"+NORM+" of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM; break;
	}

	
	User->set_title(title);
	write("Title set.\n");
	return 1;
}