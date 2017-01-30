#include "../defs.h"

status main(string str, object PO, object User)
{
	object firstwep, firstshad, wep, shadow, offwep;
	
	if(User->query_level() < 19)
	{
		write("You are not the proper level yet.\n");
		return 1;
	}
	if(!str)
	{
                offwep = (object)PO->query_offwep();
		if(offwep) {
		User->stop_offwielding(); return 1; }
	else write("Put what in your offhand?\n"); return 1; }
	wep = present(str, User);
        offwep = (object)PO->query_offwep();
	if(!wep) { write("You don't have that!\n"); return 1; }
	if(!wep->weapon_class()) { write("That is not a weapon!\n"); return 1; }
	if(wep->two_handed()) {
		write("You cannot offhand a two-handed weapon.\n"); return 1; }
	if((int)wep->offwield_function() == 2){
		write("You cannot offhand a two-handed weapon.\n"); return 1; }
	if(wep->query_bloodfist_wep_shadow()){
		write("You cannot offhand forged weapons.\n"); return 1; }
        firstwep = (object)User->query_weapon();
	if(!firstwep) {
		write("You must wield a weapon before you can offhand.\n"); return 1; }
	if(firstwep->two_handed()) {
		write("You cannot offhand while wielding a two-handed weapon.\n"); return 1; }
	if(wep->query_wielded()) {
		write("You cannot offhand a wielded weapon!\n"); return 1; }
	if(offwep && (object)offwep->query_wielded_by() == User)
	{
		write("You are already offwielding "+offwep->query_name()+".\n");
		return 1;
	}
	
	PO->set_offwep(wep);
	PO->set_firstwep(firstwep);
	
	if(wep->offwield(User))
	{
		write("You grab your "+wep->query_type()+" and twirl it around with swift precision.\n");
		PO->set_offwep(wep);
		return 1;
	}
	return 1;
}
	/*firstshad = clone_object(OBJPATH+"wepshad2.c");
	firstshad->start_wep_shadow(firstwep);*
	{
		object *inv;
		int x, s;
		inv=all_inventory(User);
		s=sizeof(inv);
		for(x=0;x<s;x++) {
			if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) {
				tell_object(User, "You cannot use a shield while dual wielding. The shield disappears.\n");
					transfer(inv[x],"/room/void");
					destruct(inv[x]);
					}
				}
			}
return 1; }*/
	
