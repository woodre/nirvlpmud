#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object poison, poison2, shadob, shadob2, weapon;
	string what, what2;
	
	
	if(!str || sscanf(str, "%s to %s", what, what2) != 2){
		write("Usage: apply <poison> to <weapon>\n");
		return 1;
	}
	
	poison = present("shinshi_deadly_poison", User);
	poison2 = present("shinshi_instant_poison", User);
	
	if(!poison && !poison2){
		write("You don't have that poison!\n");
		return 1;
	}
	
	/*if(what != "deadly" || what != "instant"){
		write("You don't have that!\n");
		return 1;
	}*/
	
	weapon = present(what2, User);
	
	if(!weapon){
		write("You don't have that weapon!\n");
		return 1;
	}
	
	if(!weapon->is_weapon()){
		write("You can only apply poison to a weapon!\n");
		return 1;
	}
	
	if(weapon->is_poisoned()){
		write("That weapon is already coated in poison!\n");
		return 1;
	}
	
	if(what == "deadly" && poison){
		destruct(poison);
		write("You carefully apply the "+HIG+"deadly"+NORM+" poison onto your weapon.\n");
		shadob = clone_object(OBJPATH+"shadow.c");
		shadob->start_it(weapon);
		return 1;
	}
	
	else if(what == "instant" && poison2){
		destruct(poison2);
		write("You carefully apply the "+HIG+"instant"+NORM+" poison onto your weapon.\n");
		shadob2 = clone_object(OBJPATH+"shadow2.c");
		shadob2->start_it(weapon);
		return 1;
	}
	
	else{
		write("You don't have that poison.\n");
		return 1;
	}
	return 1;
}