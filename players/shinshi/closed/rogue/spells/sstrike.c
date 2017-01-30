#include "../defs.h"

status main(string str, object PO, object User)
{
	int randomss, damage;
	object attacker;
	string msg1, msg2, msg3;

	randomss = random(5);
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_sp() < 30){
		write("You don't have the energy to do that.\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write("You can't attack again so soon!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write("What would you like to sinister strike?\n");
		return 1;
	}
	
	if(!User->query_weapon())
	{
		write("You cannot attack without a weapon!\n");
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
	
	switch(PO->query_sstrike()){
		case 666..1000:
		damage = 30 + random(10);
		break;
		case 333..665:
		damage = 20 + random(10);
		break;
		default:
		damage = random(15);
		break;
	}
	
	switch(damage){
		case 33..40:
		msg1 = "slam your weapon hard into "+attacker->query_name()+"'s heart";
		msg2 = " slams "+possessive(User)+" weapon hard into your heart";
		msg3 = " slams "+possessive(User)+" weapon hard into "+attacker->query_name()+"'s heart";
		break;
		case 28..32:
		msg1 = "jam your weapon into "+attacker->query_name()+"'s chest";
		msg2 = " jams "+possessive(User)+" weapon hard into your chest";
		msg3 = " jams "+possessive(User)+" weapon hard into "+attacker->query_name()+"'s chest";
		break;
		case 21..27:
		msg1 = "ram your weapon into "+attacker->query_name()+" hard";
		msg2 = " rams "+possessive(User)+" weapon into you hard";
		msg3 = " rams "+possessive(User)+" weapon into "+attacker->query_name()+" hard";
		break;
		case 10..20:
		msg1 = "jab your weapon deep inside "+attacker->query_name()+"'s rib cage";
		msg2 = " jabs "+possessive(User)+" weapon deep inside your rib cage";
		msg3 = " jabs "+possessive(User)+" weapon deep inside "+attacker->query_name()+"'s rib cage";
		break;
		case 5..9:
		msg1 = "focus your attacks and hit  "+attacker->query_name()+" leaving them slightly stunned";
		msg2 = " focuses "+possessive(User)+" attacks and hits you, leaving you slightly stunned";
		msg3 = " focuses "+possessive(User)+" attacks and hits "+attacker->query_name()+", leaving them slightly stunned.";
		break;
		default:
		msg1 = "attack wildly at "+attacker->query_name()+", leaving small scratches";
		msg2 = " attacks wildy at you leaving small scratches";
		msg3 = " attacks wildy at "+attacker->query_name()+" leaving small scratches";
		break;
	}
	
	User->spell_object(attacker, "sstrike", damage, 30, "You "+msg1+".\n", User->query_name()+msg2+".\n", User->query_name()+msg3+".\n");
	User->set_spell_dtype("other|physical");
	/*write("YOU DID THIS MUCH DAMAGE - "+damage+".\n");               -For Debugging Purposes ONLY!                 */
	if(PO->query_combo() < 5){
		PO->add_combo(1);
		return 1;
	}
	
	switch(randomss){
		case 0..1:
			if(PO->query_sstrike() < 1000){
				PO->add_sstrike(1);
			}
		break;
		case 3..4:
			if(PO->query_sstrike() < 1000){
				PO->add_sstrike(2);
			}
		break;
		default:
			if(PO->query_sstrike() < 1000){
				PO->add_sstrike(3);
			}
		break;
	}
		
	return 1;
}