id (str) {return str== "bushes";}
short () {return "bushes";}
long (){ write("A bunch of tropical bushes with a small sign in front of them PLEASE READ it.\n");}
get () { return 0;}
query_weight() {return 200;}
query_value() { return 0;}
init() {
  add_action("read", "read");
  add_action("enter", "enter");

return;
}
enter(){
	call_other(this_player(), "move_player","into the bushes after taking off their clothes wearing nothing but a grin#players/catwoman/kill/7");
	return 1;
	}

read(str){
if (str = "sign")
     cat ("/players/catwoman/kill/warning.txt");
	return 1;
}


