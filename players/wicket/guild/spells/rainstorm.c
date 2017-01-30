#include <ansi.h>
status main(string str, object PO, object User)
{
	int heal, cost, randomNum, length;
	
	randomNum = random(5);
	
	if(PO->query_suspend())
	{
		write(CYN+"Glyndwr"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(PO->query_WATER() < 4)
	{
		write(CYN+"Glyndwr"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(PO->query_rainstormCD())
	{
		write(CYN+"Glyndwr"+NORM+" says: You are not yet ready to do this again!\n");
		return 1;
	}
	
	if(PO->query_activeRainstorm())
	{
		write(CYN+"Glyndwr"+NORM+" says: You are already blessed with my rainstorm!\n");
		return 1;
	}
	
	switch(PO->query_rainstormLevel()){
		case 400..500:
		heal = 9 + random(17);
		length = 10;
		cost = 50;
		break;
		case 300..399:
		heal = 7 + random(14);
		length = 15;
		cost = 35;
		break;
		case 200..299:
		heal = 5 + random(11);
		length = 20;
		cost = 30;
		break;
		case 100..199:
		heal = 3 + random(8);
		length = 25;
		cost = 20;
		break;
		default:
		heal = 1 + random(5);
		length = 30;
		cost = 15;
		break;
	}
	
		
	if(User->query_sp() < cost){
		write(CYN+"Glyndwr"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(PO->query_waterbond())
	{
		heal *= 2;
	}
	
	switch(randomNum){
		case 0..1:
			if(PO->query_rainstormLevel() < 500){
				PO->add_rainstormLevel(1);
			}
		break;
		case 3..4:
			if(PO->query_rainstormLevel() < 500){
				PO->add_rainstormLevel(2);
			}
		break;
		default:
			if(PO->query_rainstormLevel() < 500){
				PO->add_rainstormLevel(3);
			}
		break;
	}
	
	PO->set_rainstorm(1);
	PO->set_rainstormLength(length);
	PO->set_rainstormNum(heal);
	PO->start_rainstormCD();
	PO->set_activeRainstorm(1);
	PO->set_niggerrig3(0);
	write(CYN+"\n\nGlyndwr"+NORM+BOLD+" summons forth an Ancient "+NORM+HIW+"Healing"+HIC+" Rain"+NORM+BOLD+" that seems to rejuvenate your wounds.\n\n"+NORM);
	return 1;
}
