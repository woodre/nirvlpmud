#include "/players/catwoman/obj/more.c"
id (str) {return str== "map";}
short () {return "A Map";}
long (){ write("You might want to READ it.\n");}
get () { return 0;}
query_weight() {return 200;}
query_value() { return 0;}
init() {
  add_action("read", "read");
return;
}
read(str){
if (str != "map") 
	return 0; 
if (str = "map")
     nmore ("/players/catwoman/obj/maptxt");
	return 1;
}


