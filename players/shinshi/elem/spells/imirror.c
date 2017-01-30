#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	int imirror, chance, miss;
	object attacker;
	
	imirror = random(5);
	chance = random(11);
	
	
	if(PO->query_suspend())
	{
		write(CYN+"Glyndwr"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(User->query_ghost())
	{
		return 0;
	}
	
	if(PO->query_WATER() < 6)
	{
		write(CYN+"Glyndwr"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(PO->query_imirrorCD())
	{
		write(CYN+"Glyndwr"+NORM+" says: You are not ready to do this again yet!\n");
		return 1;
	}
	
	if(User->query_sp() < 45){
		write(CYN+"Glyndwr"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}

	if(!str && !User->query_attack()){
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but who are you attacking again?\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but there is no"+RED+" "+str+" "+NORM+"here.\n");
		return 1;
	}
	if(!living(attacker)){
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but how are you suppose to attack that?\n");
		return 1;
	}
	
	if(attacker->is_wizard())
	{
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but casting this on a Wizard is not allowed.\n");
		return 1;
	}
	
	switch(PO->query_imirror()){
		case 333..500:
		miss = 9;
		break;
		case 200..332:
		miss = 7;
		break;
		case 100..199:
		miss = 5;
		break;
		default:
		miss = 3;
		break;
	}
	
	if(chance > miss)
	{
		write(BOLD+"Your "+NORM+CYN+"ice mirror"+NORM+BOLD+" shatters into millions of pieces!\n"+NORM);
		PO->start_imirrorCD();
		return 1;
	}
	
	if(chance < miss)
	{
		write(BOLD+"You summon the powers of "+NORM+CYN+"Glyndwr"+NORM+BOLD+" to form a giant mirror of "+CYN+"ice"+NORM+BOLD+".\n"+NORM);
		write(BOLD+attacker->query_name()+" "+BOLD+"stares deep into the mirror. "+attacker->query_name()+"'s\n"+NORM);
		write(BOLD+"deepest, darkest fears come to life!\n"+NORM);
		write("\n"+attacker->query_name()+" runs in fear!\n"+NORM);
		tell_object(attacker, BOLD+User->query_name()+" summons the powers of "+NORM+CYN+"Glyndwr"+NORM+BOLD+" to form a giant\n"+NORM);
		tell_object(attacker, BOLD+"mirror of "+CYN+"ice"+NORM+BOLD+". You stare deep into the mirror. The mirror shows you\n"+NORM);
		tell_object(attacker, BOLD+"your deepest, darkest, fears and you run in fear!\n"+NORM);
		attacker->run_away();
		PO->start_imirrorCD();
	}
	
	switch(imirror){
		case 0..1:
			if(PO->query_imirror() < 500){
				PO->add_imirror(1);
			}
		break;
		case 3..4:
			if(PO->query_imirror() < 500){
				PO->add_imirror(2);
			}
		break;
		default:
			if(PO->query_imirror() < 500){
				PO->add_imirror(3);
			}
		break;
	}
	User->add_spell_point(-45);
	return 1;
}