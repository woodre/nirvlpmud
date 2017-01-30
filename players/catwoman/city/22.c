object ob1, ob2;
reset(arg) {
	if(!ob1){
		ob1 = clone_object("players/catwoman/monster/pirate");
		move_object(ob1, this_object());
		}
	if(!ob2){
		ob2 = clone_object("players/catwoman/weapon/sword");
		move_object(ob2, ob1);
		}

     set_light(1);
     if (arg) return;
}

init() {

     add_action("north", "north");

     add_action("south", "south");
     add_action("pick", "pick");

   }
pick(){
	write("No stealing!\n");
	return 1;
}
	

north() {
  call_other(this_player(),"move_player", "north#players/catwoman/city/23");
  return 1;
}

south() {
  call_other(this_player(),"move_player", "south#players/catwoman/city/21");
  return 1;
}
short() { return "A pirate ship"; }

long() {
 write("A Pirate Ship\n");
 write("This is the main deck of the ship\n");
write("Surrounding the ship are the eel infested waters of Metropolis Bay\n");
write("		Obvisous exits:  north, south\n");
}

realm() { return "NT";}


