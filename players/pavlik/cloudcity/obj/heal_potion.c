/*
 * Heal Potion
 * 3 Shots of heal_self( 30 + random(15) )
 * Heal Type: intox (7)
 * Cost: 2160 (720 per shot)
 */
#include "/players/pavlik/closed/colors.h"
#define ME capitalize(this_player()->query_real_name())

int sips_taken;

id(str) {
 return str == "vial" || str == "heal" || str == "purple" || str == "purple vial";
}

reset(arg){
  if(arg) return;
  sips_taken = 0;
}

long() {
  write("A small vial filled with foul smelling "+MAG+"purple liquid"+NORM+".\n");
  write("There are " + (3-sips_taken) + " "+MAG+"sips"+NORM+" remaining.\n");
}

short() {
  return "A Vial with with "+MAG+"Purple Liquid "+HIM+"("+(3-sips_taken)+")"+NORM;
}

init() {
  add_action("sip","sip");
}

is_heal() { return "intox"; }

query_potence() { return 35; }

query_save_flag() { return 1; }

get(){ return 1; }

query_weight() { return 1; }

sip(arg){
  if(id(arg) && environment() == this_player()) {
	if(!this_player()->drink_alcohol(7)) {
		write("You can't stomach the purple liquid right now.\n");
		return 1;
	}
	write("You uncork the small vial and take a sip of the purple liquid.\n");
	write("You eyes water at the foul smell, but you feel better.\n");
	say(ME+" takes a sip from a small vial.\n");
	call_other(this_player(), "heal_self", 30+random(15));
	write(HIM+"Hp: "+this_player()->query_hp()+"   Sp: "+this_player()->query_sp()+NORM+"\n");
	sips_taken++;
	if(sips_taken >= 3){
		write("You finish the bottle.\n");
		this_player()->add_weight(-1);
		destruct(this_object());
		return 1;
	}
	else {
		write("You have "+MAG+(3 - sips_taken)+NORM+" sips remaining.\n");
	}
	return 1;
  }
}

