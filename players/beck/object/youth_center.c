#include "/players/beck/esc.h"

id(str) { return str=="center" || str=="center"; }
reset () {}
short() {
	return ""+BOLD+CYAN+"Angel Grove Youth Center"+OFF+"";
}
long() {
write("If you want to check out the youth center\n"+
"you should enter it.\n");
}
init() {
	add_action("enter","enter");
	}
enter(arg) {
if(!arg){write("Where do you want to enter?\n"); return 1;}
if(arg !="center"){write("You can only enter the center.\n"); return 1;}
call_other(this_player(),"move_player","enter#/players/beck/room/youth_center.c");
return 1;
}
get() {
	tell_object(this_player(), "There's no way you can pick up a building.\n");
	return 0;
	}
query_weight() { return 0; }
query_value() { return 5000; }
