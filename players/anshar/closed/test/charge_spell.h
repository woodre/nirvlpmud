/*	Charge <hp> - move hp into crystal component, can then move to sp..  
		80%	- max 100..  1:60 crystal breaks when 'drain'ed
	XP: 300k  SP: 5  HP: x  C: crystal(1300,x)  D: 30  GXP: amnt stored */

charge_spell(arg){
	object comp;
	int x;
        int charge;
	if(arg) return 0; 
	x=arg;
        comp = present("charge_crystal", USER);
	if(!comp){
	    write("You lack the spell component to cast this spell.\n");
		return 1;
	}
	charge = (x * 4 / 5);
	write("You charge the crystal with "+charge+" spell points...\n"+
		"The spell leaves you feeling very drained.\n");
	say(USER->QN+" suddenly looks very drained.\n");
	comp->charge_crystal(charge);
	USER->hit_player(x);
	USER->add_spell_point(-5);
	this_object()->adj_guild_exp(charge);
	return 1;
}

