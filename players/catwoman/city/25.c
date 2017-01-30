reset(arg) {
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
  call_other(this_player(),"move_player", "north#players/catwoman/city/10");
  return 1;
}

south() {
  this_player()->move_player("south#players/catwoman/city/26.c");
  return 1;
}
short() { return "Second Street"; }

long() {
 write("Second Street\n");
 write("This is Second Street in Metropolis\n");
 write("to the south is a dead end Alley north is Main Street\n");
 write("     Obvious exits: north, south\n");
}

realm() { return "NT";}

