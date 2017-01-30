status main(string str, object PO, object User)
{
	int randomsap, length;
	object attacker, stun, prevent;

	randomsap = random(5);
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_level() < 17	){
		write("You cannot use that ability yet.\n");
		return 1;
	}
	
	if(User->query_sp() < 50){
		write("You don't have the energy to do that.\n");
		return 1;
	}
	
	/* do this check first - no point validating a target if you can't use the ability */
	if(present("shinshi_stop_sap", User)){
		write("You cannot sap a target again so soon!\n");
		return 1;
	}	
	
	if(!str) { /* the player didn't enter a target */
		attacker = (object)User->query_attack(); /* get the player's current combat target */
		if(!attacker || !present(attacker, environment(User))) { /* not in combat, or else his target just left the room */
			write("Who did you want to sap?\n");  /* Notify the player of their mistake */
		}
	} else { /* the player did enter a target */
		attacker = present(str, environment(User)); /* see if the target the player entered is there */
		if(!attacker) { /* the target the player entered doesn't exist */
			write("You don't see "+str+" here.\n"); /* Notify the player of their mistake */
			return 1;
		}
	}
	
	/* Use the mud's built in code to check if the attack is allowed */
	if(!User->valid_attack(attacker))
	{
		return 1;
	}
	
/*	
	if(!str && !User->query_attack()){
		write("What would you like to sap?\n");
		return 1;
	}
		
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(str, environment(User))){
		write("You don't see "+str+" here.\n");
		return 1;
	}
	
	if(attacker->is_player() && attacker->query_level() > 20){
		write("You cannot do that to a wizard!!\n");
		return 1;
	}
	*/

	/*
	if(attacker->is_player() && !attacker->query_pl_k()){
		write("You cannot stun a non-PK player!\n");
		return 1;
	}
	*/
	if(present("stun", attacker)){
		write(attacker->query_name()+" is already sapped!\n");
		return 1;
	}
	
	switch(PO->query_sap()){
		case 666..1000:
		length = 5;
		break;
		case 333..665:
		length = 3;
		break;
		default:
		length = 1;
		break;
	}
	
		
	if(PO->query_combo() < 5){
		PO->add_combo(1);
	}

	write("You slam the hilt of your weapon against "+attacker->query_name()+"'s head, stunning them.\n");
	stun = clone_object("/players/shinshi/closed/rogue/objects/stun.c");
	prevent = clone_object("/players/shinshi/closed/rogue/objects/nosap.c");
	move_object(stun, attacker);
	move_object(prevent, User);
	stun->set_saplength(length);
	prevent->start_it();
	/*tell_room(environment(User), "DEBUG: STUN HAS BEEN APPLIED!\n");*/
	User->add_spell_point(-50);
	
	switch(randomsap){
		case 0..1:
			if(PO->query_sap() < 995){
				PO->add_sap(10);
			}
		break;
		case 3..4:
			if(PO->query_sap() < 995){
				PO->add_sap(20);
			}
		break;
		default:
			if(PO->query_sap() < 995){
				PO->add_sap(30);
			}
		break;
	}
	return 1;
}
