
id(str) { return str=="structure" || str=="structure"; }
reset () {}
short() {
	return "A Large Concrete Structure";
}
long() {
write("Its a large building made entirely of steel renforced concrete.\n"+
"There seems to be no way in, except for a small crack near the ground.\n"+
"Maybe you could try and 'sneak into' it.\n");
}
init() {
	add_action("sneak","sneak");
	}
sneak(arg) {
if(!arg){write("Where do you want to sneak?\n"); return 1;}
if(arg=="into structure"){
call_other(this_player(),"move_player","sneak#/players/beck/Rangers/Room/CommandCenter.c");
return 1;
}
write("You can only 'sneak into structure'.\n"); return 1;}
get() {
	tell_object(this_player(), "There's no way you can pick up a concrete building.\n");
	return 0;
	}
query_weight() { return 0; }
query_value() { return 5000; }
