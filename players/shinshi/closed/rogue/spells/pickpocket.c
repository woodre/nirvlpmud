#include "../defs.h"

status main(string str, object PO, object User)
{
	int rand, money, ste;
	object ob, stopper;

	rand = random(9);
	
	if(User->query_extra_level() < 18)
	{
		write("You cannot use that ability yet!\n");
		return 1;
	}
	
    if(present("shinshi_stop_pp", User)){
	    write("That ability is still on cooldown!\n");
	    return 1;
    }
    
    if(!PO->query_stealthed()){
	    write("You must be stealthed to do that!\n");
	    return 1;
    }
    
    if(User->query_sp() < 20){
	    write("You do not have the energy to do that!\n");
	    return 1;
    }
	
	if(!str){
		write("Who would you like to pickpocket?\n");
		return 1;
	}
	
	ob = present(str, environment(User));
	
	if(!ob){
		write("That is not here to pickpocket!\n");
		return 1;
	}
	
	if(!living(ob)){
		write("You cannot pickpocket that!\n");
		return 1;
	}
	
	if(!ob->is_npc()){
		write("You cannot use that on players!\n");
		return 1;
	}
	
	ste = (int)User->query_attrib("ste");
	
	if(ob){
		if(ob->query_level() < User->query_level()){
			if((ste * 5) / 3 > 45){
				money = 25 + random(76);
				User->add_money(money);
				write("You pickpocket "+money+" golden coins from "+ob->query_name()+".\n");
				stopper = clone_object(OBJPATH+"nopp.c");
				move_object(stopper, User);
				stopper->start_it();
				User->add_spell_point(-20);
				return 1;
			}
			else{
				write(ob->query_name()+" notices you sneaking into their stash and attacks!\n");
				stopper = clone_object(OBJPATH+"nopp.c");
				move_object(stopper, User);
				stopper->start_it();
				User->add_spell_point(-20);
				return 1;
			}
			return 1;
		}
		else{
			if((ste * 5) / 3 > 45){
				money = 250 + random(751);
				User->add_money(money);
				write("You pickpocket "+money+" golden coins from "+ob->query_name()+".\n");
				stopper = clone_object(OBJPATH+"nopp.c");
				move_object(stopper, User);
				stopper->start_it();
				User->add_spell_point(-20);
				return 1;
			}
			else{
				write(ob->query_name()+" notices you sneaking into their stash and attacks!\n");
				stopper = clone_object(OBJPATH+"nopp.c");
				move_object(stopper, User);
				stopper->start_it();
				User->add_spell_point(-20);
				return 1;
			}
			return 1;
		}
		return 1;
	}
	return 1;
}