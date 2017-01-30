/*
Level 6 Combat Spell: Hypermode - The Classic is back!  Well, Kinda :)
*/

#include "/players/chip/venom2/sdefine.h"

main(string str, object gob, object player)
{
	
	if(USER->query_ghost()) return 0;
	if(COM < 6) return 0;
if(!USER->query_pl_k()){ write("You must set pk to use this ability.\n"); return 1; }
	if(USER->query_sp() < 50){
		tell_object(USER, "You lack the energy for Hypermode.\n");
		return 1;
	}
	if(GOB->query_mp() < 5){
		tell_object(USER, "You lack the "+HIK+"Dark Matter"+NORM+" to do that.\n");
		return 1;
	}
	if(GOB->query_hypermode()){
		tell_object(USER, "Hypermode is already on.\n");
		return 1;
	}
	tell_object(USER,
		BOLD+"Your body tightens as symbiotic matter flows into your veins and muscles..."+NORM+"\n"+
	COLOR+"Your motions become a blur!"+NORM+"\n");
	tell_room(environment(USER),
		BOLD+USER->query_name()+"'s body darkens as something "+HIK+"Black"+NORM+" courses through "+USER->POS+" veins...\n"+
	NORM+COLOR+USER->POS+" motions blur!"+NORM+"\n", ({ USER }));
	GOB->set_hypermode(58 + (COM * 2) + USER->query_attrib("wil"));
	USER->add_spell_point(-50);
	GOB->add_mp(-5);
	return 1;
}

