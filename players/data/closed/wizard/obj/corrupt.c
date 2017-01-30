#include "/players/maledicta/ansi.h"
#define USER environment()

int strength;
string owner;

reset(){
	call_out("dest_it", 30);
}

get(){ return 1; }
drop(){ return 1; }

id(str){ return str == "corruption_object"; }

dest_it(){
	tell_object(USER, "You refuse to be corrupted.\n");
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
	capitalize(owner)+" wishes to corrupt your soul. \n"+
	"Do you accept? <y/N> ");
 add_action("woot");  add_xverb("");
 }



set_owner(str){ owner = str; }
query_owner(){ return owner; }

set_strength(int i){ strength = i; }
query_strength(){ return strength; }


woot(str){
	if(str == "y" || str == "Y" || str == "yes"){
		if(!present(owner, environment(USER))){
			tell_object(USER,
			capitalize(owner)+" is not present to corrupt you.\n");
			remove_call_out("dest_it");
			destruct(this_object());
			return 1;
		}
		tell_object(USER,
		"You accept corruption.  You feel evil violate your soul.\n");
		tell_room(environment(USER),
		USER->query_name()+" cries out in evil glee.\n", ({USER}));
		USER->add_alignment(- (strength * 200));
		remove_call_out("dest_it");
      destruct(this_object());
		return 1;
	}
	else{
		remove_call_out("dest_it");
		tell_object(USER, "You decline corruption.\n");
		destruct(this_object());
		return;
	}
		remove_call_out("dest_it");
		tell_object(USER, "You decline corruption.\n");
		destruct(this_object());
		return;
}	
