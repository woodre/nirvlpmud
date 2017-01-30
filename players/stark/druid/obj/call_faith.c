#include "/players/stark/defs.h"
id(str) { return str == "portal"; }

short() {
    return "A shimmering portal"; }

long() { return "A translucent shimering portal you could 'enter'";}

init() {
add_action("enter","enter");
}

enter(arg){
	if(!arg){
		write("Enter what?");
		return 1;
	}

	if(arg == "portal"){
		tell_room("/players/stark/workroom", "A shimering portal opens up.\n");
		write("You enter the portal and find yourself in the home of the druids\n");
		TP->move_player("portal#/players/stark/workroom");
		tell_room("/players/stark/workroom", "The shimering fades...\n");
		return 1;
	}
}

