#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	int randomambush, damage, scar;
	object attacker, stopper, scar2;
	string msg1, msg2, msg3;
	
	randomambush = random(5);
	scar = random(666);
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(!str){
		write("Who would you like to ambush?\n");
		return 1;
	}
	
	if(User->query_extra_level() < 22){
		write("You cannot use that ability yet!\n");
		return 1;
	}
	
    if(!present("didshadowstep", User)){
		write("You can only do that after shadowstepping!\n");
		return 1;
	}
	
	if(!PO->query_stealthed()){
		write("You must be stealthed to do that!\n");
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
	
	if(!str){
		write("Who are you trying to attack?\n");
		return 1;
	}
	
	attacker = present(str, environment(User));
	
	if(!living(attacker)){
		write("That isn't alive to attack!\n");
		return 1;
	}
	
	switch(PO->query_ambush()){
		case 666..1000:
		damage = 50 + random(20);
		break;
		case 333..665:
		damage = 40 + random(15);
		break;
		default:
		damage = 35 + random(10);
		break;
	}
	
	switch(damage){
		case 50..60:
		msg1 = "slide from the "+HIBLK+"shadows"+NORM+" silently\n"+
			   "as you ambush "+attacker->query_name()+". The damage leaves\n"+
				""+attacker->query_name()+" massively wounded.\n";
		msg2 = " slides from the "+HIBLK+"shadows"+NORM+" silently\n"+
			   "as they ambush you. The damage leaves you massively\n"+
			   "wounded.\n";
		msg3 = " slides from the "+HIBLK+"shadows"+NORM+"silently as\n"+
			   "they ambush "+attacker->query_name()+" leaving them massively\n"+
			   "wounded.\n";
		break;
		case 40..45:
		msg1 = "slide from the "+HIBLK+"shadows"+NORM+" silently\n"+
			   "as you ambush "+attacker->query_name()+". "+attacker->query_name()+" steps\n"+
			   "back slightly as the attack"+HIR+" pierces "+NORM+"flesh\n"+
			   "causing "+HIR+"blood"+NORM+" to flow.\n";
		msg2 = " slides from the "+HIBLK+"shadows"+NORM+" silently\n"+
			   "as they ambush you. You stumble back slightly as the\n"+
			   "attack"+HIR+" pierces"+NORM+" your flesh causing "+HIR+"blood"+NORM+"\n"+
			   "to flow.\n";
		msg3 = " slides from the "+HIBLK+"shadows"+NORM+" silently as they\n"+
			   "ambush "+attacker->query_name()+". "+attacker->query_name()+" stumbles\n"+
			   "back slightly as the attack "+HIR+"pierces"+NORM+" their flesh causing "+HIR+"blood"+NORM+"to flow.\n";
		break;
		default:
		msg1 = "slide from the "+HIBLK+"shadows"+NORM+" silently\n"+
			   "as you ambush "+attacker->query_name()+". Some "+HIY+"flesh"+NORM+" is flayed off\n"+
			   "of "+attacker->query_name()+"'s body.\n";
		msg2 = " slides from the "+HIBLK+"shadows"+NORM+" silently\n"+
			   "Some of your "+HIY+"flesh"+NORM+" is flayed off of your body.\n";
		msg3 = " slides from the "+HIBLK+"shadows"+NORM+" silently\n"+
			   "as they ambush "+attacker->query_name()+". Some "+HIY+"flesh"+NORM+" is flayed off\n"+
			   "of "+attacker->query_name()+"'s body.\n";
		break;
	}
	
	if(PO->query_combo() < 5){
		PO->add_combo(1);
	}
	
	User->spell_object(attacker, "ambush", damage, 50, "\nYou "+msg1+"\n", "\n"+User->query_name()+msg2+"\n", "\n"+User->query_name()+msg3+"\n");
	User->set_spell_dtype("other|physical");
	/*write("YOU DID "+damage+" DAMAGE.\n");		For debugging purposes ONLY! */
	
	switch(randomambush){
		case 0..1:
		PO->add_ambush(10);
		break;
		case 3..4:
		PO->add_ambush(20);
		break;
		default:
		PO->add_ambush(30);
		break;
	}
	
	if(scar == 23){
		if(attacker->is_player()){
			scar2 = clone_object(OBJPATH+"scar.c");
			move_object(scar2, attacker);
			tell_object(attacker, "You scream in agony as "+User->query_name()+"'s weapons pierce your back!\n");
		}
	}
	
	stopper = present("didshadowstep", User);
	if(stopper){
		destruct(stopper);
		return 1;
	}
	
	write(attacker->query_name()+" whirls around and attacks you.\n");
	return 1;
}
