#include "/players/beck/esc.h"

id(str) { return str=="taco bell" || str=="taco bell"; }
reset () {}
short() {
   return "A " + GREEN + "Taco " + YELLOW + "Bell" + OFF;
}
long() {
write("Go inside by making a 'run for the border'.\n");
}
init() {
	add_action("run","run");
	}
run(arg) {
if(!arg){write("Make a 'run for the border'!\n"); return 1;}
if(arg =="for the border"){write("You are feeling hungry for some cheap mexican food.\n");
call_other(this_player(),"move_player","border#/players/beck/room/taco.c");
return 1;
}
write("Make a run for the border!\n"); return 1;}
get() {
	tell_object(this_player(), "There's no way you can pick up a building.\n");
	return 0;
	}
query_weight() { return 0; }
query_value() { return 5000; }
