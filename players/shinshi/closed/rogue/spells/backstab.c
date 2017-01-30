#include "../defs.h"

status main(string str, object PO, object User)
{
	int randombackstab, damage;
	object attacker, stopper, stopper2;
	string msg1, msg2, msg3;
	
	randombackstab = random(4);
	if(User->query_ghost()){
		return 1;
	}
		
	if(User->query_extra_level() < 8){
		write("You cannot use that ability yet.\n");
		return 1;
	}
	
	if(!present("didshadowstep", User)){
		write("You can only do that after shadowstepping!\n");
		return 1;
	}
	
	if(User->query_sp() < 35){
		write("You don't have the energy to do that.\n");
		return 1;
	}
	
	if(User->query_no_spell() || User->checkNM()){
		write("You cannot use that here!\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write("You can't attack again so soon!\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write("You don't see "+str+" here.\n");
		return 1;
	}
	
	switch(PO->query_backstab()){
		case 666..1000:
		damage = 30 + random(11);   /* Max chance of 40 */
		break;		  
		case 333..665:
		damage = 25 + random(6);    /* Max chance of 30 */
        break;	  	 
	  	default:
	  	damage = 15 + random(6);    /* Max chance of 20 */
	  	break;
	  	 		
	}
	
	if(PO->query_combo() < 5){
		PO->add_combo(1);
	}
	
	msg1 = "plunge your weapons deep into the back of "+attacker->query_name()+".\n";
	msg2 = " plunges "+possessive(User)+" weapon hard into your spine";
	msg3 = " plunges "+possessive(User)+" weapon hard into "+attacker->query_name()+"'s spine";

	
	User->spell_object(attacker, "backstab", damage, 35,  "You "+msg1+".\n", User->query_name()+msg2+".\n", User->query_name()+msg3+".\n");
	User->set_spell_dtype("other|physical");
	switch(randombackstab){
		case 0..1:
		PO->add_backstab(10);
		break;
		case 3..4:
		PO->add_backstab(20);
		break;
		default:
		PO->add_backstab(30);
		break;
	}
	stopper = present("didshadowstep", User);
	if(stopper){
		destruct(stopper);
		return 1;
	}
	write(attacker->query_name()+" whirls around and attacks you.\n");
	return 1;
}
