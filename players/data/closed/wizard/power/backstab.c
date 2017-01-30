/*  Backstab - Adds a bonus to WC for one attack  */

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
	int damage;
	int total;
	object ob;

	if(!str){
		tell_object(USER,
			"Backstab who?\n");
		return 1;
	}

	if(USER->query_ghost()) return 0;
	if(!USER->query_pl_k()){
		tell_object(USER, "Assassins must be pk.\n");
		return 1;
	}
	if(USER->query_sp() < 60){
		tell_object(USER, "You are too weak to perform this.\n");
		return 1;
	}
	if(GOB->query_end() < 50){
		tell_object(USER, "You lack the endurance!\n");
		return 1;
	}
	ob = present(str, environment(USER));
	if(!ob){
		tell_object(USER,
			"You do not see "+str+" here!\n");
		return 1;
	}
	if(!living(ob)){
		tell_object(USER,
			"You cannot backstab that!\n");
		return 1;
	}
	if(!USER->query_weapon()){
		tell_object(USER, "This move requires a weapon of small type.\n");
		return 1;
	}
	if(!GOB->small_check(USER->query_weapon())){
		tell_object(USER, "You are not wielding a weapon of small type.\n");
		return 1;
	}
	if(USER->query_attack()){
		tell_object(USER, "You cannot do this while fighting!\n");
		return 1;
	}
	if(!USER->query_invis()){
		tell_object(USER, "You are not hiding!\n");
		return 1;
	}
	if(present("backstab_object", ob)){
		tell_object(USER, capitalize(str)+" is too alert!\n");
		return 1;
	}
	
	damage = GOB->get_skill(112);
	switch(damage){
	case 5..10: total = 90; break;
	case 4:     total = 70; break;
	case 3:     total = 55; break;
	case 2:     total = 40; break;
	case 1:     total = 20; break;
	}
	GOB->set_backstab(total);
	move_object(clone_object("/players/maledicta/closed/w/OBJ/backstab_ob.c"), ob);
	USER->add_spell_point(-60);
	GOB->add_end(-50);
	USER->visible();
	USER->attack_object(ob);
	return 1;
}


