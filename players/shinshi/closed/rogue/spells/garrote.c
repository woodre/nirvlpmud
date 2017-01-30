#include "../defs.h"

status main(string str, object PO, object User)
{
	object bleed, stopper, stopper2, attacker;
	int randomgarrote, length;
	
	randomgarrote = random(5);
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_extra_level() < 25){
		write("You cannot use that ability yet.\n");
		return 1;
	}
	
	if(!PO->query_stealthed()){
		write("You must be stealthed to do that!\n");
		return 1;
	}
	
	if(present("shinshi_no_garrote", User)){
		write("You cannot use that ability so soon!\n");
		return 1;
	}
	
	if(!present("didshadowstep", User)){
		write("You can only do that after shadowstepping!\n");
		return 1;
	}
	
	if(User->query_sp() < 50){
		write("You don't have the energy to do that.\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write("You can't attack again so soon!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write("What would you like to garrote?\n");
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
	if(!living(attacker)){
		write("That isn't alive to attack.\n");
		return 1;
	}
	
	switch(PO->query_garrote()){
		case 666..1000:
		length = 10;
		break;
		case 333..665:
		length = 5;
		break;
		default:
		length = 3;
		break;
	}
	
	bleed = clone_object(OBJPATH+"bleed.c");
	stopper = clone_object(OBJPATH+"nogarrote.c");
	move_object(bleed, attacker);
	move_object(stopper, User);
	write("Your weapon leaves a deep slice into "+attacker->query_name()+"'s head!\n");  /* For Debugging Purposes Only! */
	bleed->set_garlength(length);
	bleed->start_it();
	stopper->start_it();
	if(!User->query_attack()){
		User->attack_object(attacker);
	}
	User->add_spell_point(-50);

	
	if(PO->query_combo() < 5){
		PO->add_combo(1);
	}
	
	switch(randomgarrote){
		case 0..1:
			if(PO->query_garrote() < 995){
				PO->add_garrote(10);
			}
		break;
		case 3..4:
			if(PO->query_garrote() < 995){
				PO->add_garrote(20);
			}
		break;
		default:
			if(PO->query_garrote() < 995){
				PO->add_garrote(30);
			}
		break;
	}
	
	stopper2 = present("didshadowstep", User);	
	if(stopper2){
		destruct(stopper2);
		return 1;
	}
		
	return 1;
}