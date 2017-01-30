id (str) {return str== "birds";}
short () {return " Love Birds";}
long (){ write("Acouple of love birds you might want to ASK them.\n");}
get () { return 0;}
query_weight() {return 200;}
query_value() { return 0;}
init() {
  add_action("ask", "ask");
   add_action("asks", "dw");

return;
}

ask(str){
if (str != "birds") 
	return 0; 
if (str = "birds")
     cat ("/players/catwoman/monster/commands.txt");
	return 1;
}
asks(){
object ob1, ob2, ob3;
ob2 = clone_object("players/catwoman/monster/dw2");
     move_object(ob2, this_object());
return 1;

}


