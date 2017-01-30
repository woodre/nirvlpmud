#include <ansi.h>
#include "../defs.h"
	object weapon;
	int wt;

reset(arg){
	if(arg) return;
	call_out("finish_it", 3600);/* 60 minutes */
}

start_it(wep){
	
	weapon = wep;
	
	if(!weapon->query_hit_func()){
		weapon->set_hit_func(this_object());
		wt = 1;
	}
	shadow(weapon, 1);
}

short(){
	return weapon->short()+" "+HIG+"\[coated in instant poison\]"+NORM;
}

weapon_hit(atk)
{
       object poison;
	int number;
	
	number = random(100);
	
	if(number > 70 && !present("poison_damage_yo2", atk)){
		poison = clone_object(OBJPATH+"poison2.c");
		move_object(poison, atk);
		poison->start_it();
		/*tell_object(find_player("shinshi"), "DEBUG: INSTANT Poison put on the mob.\n");	 For debugging purposes*/
	}
	weapon->weapon_hit(atk);
}

is_poisoned(){
	return 1;
}

finish_it(){
	write(HIG+"The last bit of poison on your weapon drips to the floor.\n"+NORM);
	if(wt){
		weapon->set_hit_func(weapon);
	}
	bye();
}

bye(){
	destruct(this_object());
}

query_no_clean() { return 1; }
