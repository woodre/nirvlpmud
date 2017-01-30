set_offhand(ob){ offhand = ob; }
query_offhand(){ return offhand; }

zero_skill(int i){ skills[i] = 0; }
add_skill(int i){ skill_pts += i; }

offhand_cmd(str){
	object wooter;
	if(!skills[32]){ return; }
	if(offhand){
		write("You unwield your off-handed weapon.\n");
		move_object(offhand, environment());
		offhand = 0;
		offhand_wght = 0;
		USER->recalc_carry();
		return 1;
	}
	if(!str){ write("offhand wield what?\n"); return 1; }
	wooter = present(str, USER);
	if(!wooter){ write("You don't see that here!\n"); return 1; }
	if(!wooter->is_weapon()){
		write("That is not something you can offhand wield!\n");
		return 1;
	}
	if(!wooter->weapon_class()){
		write("That is not something you can offhand wield!\n");
		return 1;
	}
	if(wooter->query_wielded()){
		write("You must unwield it first!\n");
		return 1;
	}
	if(shield_check()){ write("You are using a shield!\n"); return 1; }
	if(!small_check(wooter)){ write("You cannot use that as an offhanded parrying weapon!\n"); return 1; }
	if(wooter->two_handed()){ write("You cannot offhand wield a two-handed weapon!\n"); return 1; }
	offhand = wooter;
	if(wooter->query_weight()) offhand_wght = wooter->query_weight();
	if(wooter->query_name()) offhand_name = wooter->query_name();
	move_object(wooter, TO);
	write("You offhand wield the "+str+".\n");
	USER->recalc_carry();
	return 1;
}

