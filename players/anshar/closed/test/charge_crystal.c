#include "/players/zeus/closed/all.h"
int charge;

reset(arg) {
  if(arg) return;
  charge = 0;
}

id(str) { return str == "crystal" || str == "charge_crystal"; }
short() { return BOLD+"A clear crystal"+NORM;   }
query_value() { return 700; }

long() {
write("This is a beautiful clear crystal.  It is perfectly cut.\n");
	if(charge > 0){
write("There is a white light coming from within the crystal.\n"+
"You could 'drain' the crystal of it's energy, "+charge+" sps.\n");
	}
	else
write("The crystal is hollow, and is empty right now.\n");
}

get() { return 1; }
query_weight() { return 0; }

query_charge(){ return charge; }

charge_crystal(int x){ charge += x; 
	if(charge >= 100)
		charge = 100;
}

dest_func(){	destruct(this_object());  }

void init(){
	add_action("drain_cmd", "drain");
}

status drain_cmd(string str){
	if(!str) return 0;
	if(str == "crystal"){
		if(charge <= 0){
			write("The crystal is empty of energy.\n");
			return 1;
		}
		else {
			write("You drain the crystal of it's energy.\n");
			say(TP->QN+" holds a crystal in "+TP->POS+" hand.\n");
			TP->add_spell_point(charge);
			charge = 0;
			if(!random(60)){
				write(BOLD+"The crystal shatters!\n"+NORM);
				dest_func();
				return 1;
			}
			return 1;
		}
		return 1;
	}
	else return 0;
	return 1;
}

