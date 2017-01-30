id (str) {return str== "picture";}
short () {return "A picture";}
long (){ write("You might want to READ it.\n");}
get () { return 0;}
query_weight() {return 200;}
query_value() { return 0;}
init() {
  add_action("read", "read");

return;
}

read(str){
if (str != "picture") 
	return 0; 
if (str = "picture")
     cat ("/players/catwoman/kj");
	return 1;
}


