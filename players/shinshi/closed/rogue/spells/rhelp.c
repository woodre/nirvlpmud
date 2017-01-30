#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	if(!str){ cat(HELPPATH+"main.txt"); }
	else if(str == "stealth"){ cat(HELPPATH+"stealth.txt"); return 1; }
	else if(str == "sstrike"){ cat(HELPPATH+"sstrike.txt"); return 1; }
	else if(str == "evis"){ cat(HELPPATH+"evis.txt"); return 1; }
	else if(str == "ambush"){ cat(HELPPATH+"ambush.txt"); return 1; }
	else if(str == "apply"){ cat(HELPPATH+"apply.txt"); return 1; }
	else if(str == "backstab"){ cat(HELPPATH+"backstab.txt"); return 1; }
	else if(str == "blind"){ cat(HELPPATH+"blind.txt"); return 1; }
	else if(str == "expose"){ cat(HELPPATH+"expose.txt"); return 1; }
	else if(str == "garrote"){ cat(HELPPATH+"garrote.txt"); return 1; }
	else if(str == "offhand"){ cat(HELPPATH+"offhand.txt"); return 1; }
	else if(str == "pickpocket"){ cat(HELPPATH+"pickpocket.txt"); return 1; }
	else if(str == "prep"){ cat(HELPPATH+"prep.txt"); return 1; }
	else if(str == "sap"){ cat(HELPPATH+"sap.txt"); return 1; }
	else if(str == "shadowstep"){ cat(HELPPATH+"shadowstep.txt"); return 1; }
	else if(str == "skills"){ cat(HELPPATH+"skills.txt"); return 1; }
	else if(str == "stealth"){ cat(HELPPATH+"stealth.txt"); return 1; }
	else if(str == "vanish"){ cat(HELPPATH+"vanish.txt"); return 1; }
	else if(str == "abilities"){ cat(HELPPATH+"abilities.txt"); return 1; }
	else if(str == "basics"){ cat(HELPPATH+"basics.txt"); return 1; }
	else if(str == "recruitment"){ cat(HELPPATH+"recruitment.txt"); return 1; }
	else if(str == "leaving"){ cat(HELPPATH+"leaving.txt"); return 1; }
	else if(str == "rules"){ cat(HELPPATH+"rules.txt"); return 1; }
	else if(str == "dissect"){ cat(HELPPATH+"dissect.txt"); return 1; }
	else {
		write("There is no help file on "+str+".\n");
		return 1; }
	return 1;
}