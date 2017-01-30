#include "/players/maledicta/ansi.h"
#define USER environment()

int strength;
string owner;

reset(){
	call_out("dest_it", 30);
}

get(){ return 1; }
drop(){ return 1; }

id(str){ return str == "redemption_object"; }

dest_it(){
	tell_object(USER, "You refuse to be redeemed.\n");
	destruct(this_object());
	return 1;
}

init(){
 if(!environment()) return;
 if(USER->query_attack()){
			remove_call_out("dest_it");
			destruct(this_object());
			return 1;
		   }
tell_object(USER,
	capitalize(owner)+" wishes to redeem you of your sins. \n"+
	"Do you accept? <y/N> ");
#ifndef __LDMUD__
 add_action("woot");  add_xverb("");
#else
 add_action("woot", "", 3);
#endif
 }



set_owner(str){ owner = str; }
query_owner(){ return owner; }

set_strength(int i){ strength = i; }
query_strength(){ return strength; }


woot(str){
	if(str == "y" || str == "Y" || str == "yes"){
		if(!present(owner, environment(USER))){
			tell_object(USER,
			capitalize(owner)+" is not present to redeem you.\n");
			remove_call_out("dest_it");
			destruct(this_object());
			return 1;
		}
		tell_object(USER,
		"You have decided to accept redemption.  You feel goodness enter your soul.\n");
		tell_room(environment(USER),
		USER->query_name()+" suddenly looks happy.\n", ({USER}));
		USER->add_alignment(strength * 200);
		remove_call_out("dest_it");
      destruct(this_object());
		return 1;
	}
	else{
		remove_call_out("dest_it");
		tell_object(USER, "You decline redemption.\n");
		destruct(this_object());
		return;
	}
		remove_call_out("dest_it");
		tell_object(USER, "You decline redemption.\n");
		destruct(this_object());
		return;
}	
