#include <ansi.h>
status main(string str, object PO, object User)
{
	int randomevis, damage;
	object attacker;
	string msg1, msg2, msg3;
	
	randomevis = random(5);
	if(User->query_ghost()){
		return 1;
	}

		
	if(User->query_level() < 16){
		write("You cannot use that ability yet.\n");
		return 1;
	}
	
	if(User->query_sp() < 50){
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
	
	if(!User->query_weapon())
	{
		write("You cannot attack without a weapon!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write("You must be in combat!\n");
		return 1;
	}
	
	attacker = (object)User->query_attack();
	/*if(!attacker){
		attacker = present(str, environment(User)); }*/
	/*if(!attacker || !present(attacker, environment(User))){
		write("You don't see "+str+" here.\n");
		return 1;
	}*/
	if(!attacker){
		write("You must be in combat!\n");
		return 1;
	}
	if(!living(attacker)){
		write("That isn't alive to attack.\n");
		return 1;
	}
	
	if(PO->query_combo() == 0 && !attacker){
		write("You must be in combat!\n");
		return 1;
	}
	
	if(PO->query_combo() == 0 && attacker){
		write("You must have at least one combo point!\n");
		return 1;
	}
	
	switch(PO->query_evis()){
		case 666..2000:
			if((int)PO->query_combo() == 1){
				damage = 20 + random(20);
				PO->set_combo(0);
			}
			
		  else if((int)PO->query_combo() == 2){
			  damage = 25 + random(20);
			  PO->set_combo(0);
		  }
		  
		  else if((int)PO->query_combo() == 3){
			  damage = 30 + random(20);
			  PO->set_combo(0);
		  }
		  
		  else if((int)PO->query_combo() == 4){
			  damage = 35 + random(20);
			  PO->set_combo(0);
		  }
		  
		  else if((int)PO->query_combo() == 5){
			  damage = 40 + random(20);
			  PO->set_combo(0);
		  }
		  break;
		  
		  case 333..665:
		  	if((int)PO->query_combo() == 1){
			  	damage = 10 + random(15);
			  	PO->set_combo(0);
		  	}
		  	
		  	if((int)PO->query_combo() == 2){
		  		damage = 15 + random(15);
		  		PO->set_combo(0);
	  		}
	  		
	  		if((int)PO->query_combo() == 3){
		  		damage = 20 + random(15);
		  		PO->set_combo(0);
	  		}
	  		
	  		if((int)PO->query_combo() == 4){
		  		damage = 25 + random(15);
		  		PO->set_combo(0);
	  		}
	  		
	  		if((int)PO->query_combo() == 5){
		  		damage = 30 + random(15);
		  		PO->set_combo(0);
	  		}
	  	 break;
	  	 
	  	 default:
	  	 		if((int)PO->query_combo() == 1){
		  	 		damage = 10;
		  	 		PO->set_combo(0);
	  	 		}
	  	 		
	  	 		if((int)PO->query_combo() == 2){
		  	 		damage = 15;
		  	 		PO->set_combo(0);
	  	 		}
	  	 		
	  	 		if((int)PO->query_combo() == 3){
		  	 		damage = 20;
		  	 		PO->set_combo(0);
	  	 		}
	  	 		
	  	 		if((int)PO->query_combo() == 4){
		  	 		damage = 25;
		  	 		PO->set_combo(0);
	  	 		}
	  	 		
	  	 		if((int)PO->query_combo() == 5){
		  	 		damage = 30;
		  	 		PO->set_combo(0);
	  	 		}
	  	 break;
	}
	 
	 
	switch(damage){
		case 45..60:
		msg1 = "run your blade through "+attacker->query_name()+"'s torso spilling "+HIR+"blood"+NORM+" and "+HIR+"organs"+NORM;
		msg2 = " runs "+possessive(User)+" blade through your torso spilling "+HIR+"blood"+NORM+" and "+HIR+"organs"+NORM;
		msg3 = " runs "+possessive(User)+" blade through "+attacker->query_name()+"'s torso spilling "+HIR+"blood"+NORM+" and "+HIR+"organs"+NORM;
		break;
		case 30..44:
		msg1 = "run your blade through "+attacker->query_name()+"'s chest, slicing them open and making the "+HIR+"blood"+NORM+" pour"+NORM;
		msg2 = " runs "+possessive(User)+" blade through your chest, slicing you open and making the "+HIR+"blood"+NORM+" pour"+NORM;
		msg3 = " runs "+possessive(User)+" blade through "+attacker->query_name()+"'s chest, slicing them open and making the "+HIR+"blood"+NORM+" pour"+NORM;
		break;
		case 15..29:
		msg1 = "slice your blade through "+attacker->query_name()+"'s inner thigh, making "+HIR+"blood"+NORM+" spray in all directions"+NORM;
		msg2 = " slices "+possessive(User)+" blade through your inner thigh, making "+HIR+"blood"+NORM+" spray in all directions"+NORM;
		msg3 = " slices "+possessive(User)+" blade through "+attacker->query_name()+"'s inner thigh, causing "+HIR+"blood"+NORM+" to spray in all directions"+NORM;
		break;
		case 5..14:
		msg1 = "slide your blade across "+attacker->query_name()+"'s upper torso, slicing their skin just enough to make "+HIR+"blood"+NORM+" start to drip"+NORM;
		msg2 = " slices "+possessive(User)+" blade across your upper torso, slicing your skin just enough to make "+HIR+"blood"+NORM+" start to drip"+NORM;
		msg3 = " slices "+possessive(User)+" blade across "+attacker->query_name()+"'s upper torso, slicing "+possessive(User)+" skin just enough to make "+HIR+"blood"+NORM+" start to drip"+NORM;
		break;
		default:
		msg1 = "barely drag your blade across "+attacker->query_name()+"'s chest, leaving a slight scratch"+NORM;
		msg2 = " barely drags "+possessive(User)+" blade across your chest, leaving a slight scratch"+NORM;
		msg3 = " barely drags "+possessive(User)+" blade across "+attacker->query_name()+"'s chest, leaving a slight scratch"+NORM;
		break;
	}
	
	
	User->spell_object(attacker, "evis", damage, 50, "You "+msg1+".\n", "\n"+User->query_name()+msg2+".\n", "\n"+User->query_name()+msg3+".\n");
	User->set_spell_dtype("other|physical");
	switch(randomevis){
		case 0..1:
		PO->add_evis(1);
		break;
		case 3..4:
		PO->add_evis(2);
		break;
		default:
		PO->add_evis(3);
		break;
	}
	return 1;
}
