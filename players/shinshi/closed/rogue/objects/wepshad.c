#define myattack environment(weapon)->query_attack()
object weapon, wielder;
	
start_wep_shadow(object ob){
	if(!ob){ return; }
	if(!environment(ob)) return;
	if(!environment(ob)->is_player()) return;
	weapon = ob;
	wielder = environment(weapon);
	shadow(weapon, 1);
	return 1; }
	
stop_wep_shadow() {
	object gob, fwep;
	if(!wielder) return;
	gob = present("shinshi_rogue_seal", wielder);
	if(!gob) gob = present("gob", wielder);
	if(gob) {
		tell_object(wielder, "You stop offwielding.\n");
		gob->remove_offwep();
		fwep = gob->query_firstwep();
		if(fwep) fwep->stop_wep_shadow();
		}
	shadow(weapon, 0);
	destruct(this_object());
	return 1; }
	
drop(str) {
	int retVal;
	retVal = (int)weapon->drop(str);
	if(!retVal)
	stop_wep_shadow();
	return retVal;
}

un_wield() {
	weapon->un_wield();
	stop_wep_shadow();
	return 1;
}

query_pro_weapon() { return 1; }

query_offwielded() { return 1; }

wield(str) {
	if(weapon->id(str)) {
		write("You cannot wield an offhanded weapon!\n");
		return 1; }
}

dual_hit() {
	int total;
	if(!wielder || !wielder->query_weapon()) return;
	total += weapon->weapon_class();
	total += weapon->hit(wielder->query_attack());
	if(present("shinshi_rogue_seal", wielder))
		dual_message(total);
		return total;
}

dual_message(num) {
	int ran;
	string mess, color, weaponname;
	if(!weapon) return;
	if(!weapon->query_name()) weaponname = "weapon";
	else
		weaponname = capitalize(weapon->query_name());
		ran = random(100);
		if(!ran || ran > 4) return;
		if(ran == 1){
			tell_object(wielder, "You spin in circles, slicing anything that you can touch!\n");
			return 1;
		}
		
		if(ran == 2){
			tell_object(wielder, "You jump high into the sky and bring your weapon deep into your enemy!\n");
			return 1;
		}
		
		if(ran == 3){
			tell_object(wielder, "You fade in and out of the shadows and bring your weapon to meet with your enemy's face!\n");
			return 1;
		}
		return 1;
}

short(){
	return weapon->short()+" (offhanded)"; }

query_wep_shadow() { return 1; }
