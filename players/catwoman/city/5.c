object ob1, ob2;
reset(arg) {
	if(!ob1){
		ob1 = clone_object("players/catwoman/monster/glantern");
		move_object(ob1, this_object());
		}

     set_light(1);
     if (arg) return;
}

init() {
     add_action("south", "south");
     add_action("pick", "pick");

   }
pick(){
	write("No stealing!\n");
	return 1;
}
	
south() {
  call_other(this_player(),"move_player", "south#players/catwoman/city/4");
  return 1;
}
short() { return "First Street"; }

long() {
 write("First Street\n");
 write("This is First street to the south is Main Street\n");
 write("     Obvious exit: south\n");
}

realm() { return "NT";}

