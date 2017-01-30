id (str) {return str== "notice";}
short () {return "A notice";}
long (){ write("You might want to READ it.\n");}
get () { return 0;}
query_weight() {return 200;}
query_value() { return 0;}
init() {
  add_action("read", "read");
  add_action("enter", "enter");
add_action("money","money");

return;
}
money(str) {
int val;
   if(!str) {
   write("Useage: money <amount>\n");
   return 1;
   }
   if (sscanf(str, "%d", val) !=1) {
   write("Useage: money <amount>\n");
   return 1;
   }
   call_other(this_player(), "add_money", val);
   write("You gain "+str+" coins.\n");
   return 1;
}
enter(){
	call_other(this_player(), "move_player","consented#players/catwoman/garden");
	return 1;
	}

read(str){
if (str != "notice") 
	return 0; 
if (str = "notice")
     cat ("/players/catwoman/consent.txt");
}


