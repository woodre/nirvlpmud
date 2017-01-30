object ob1, ob2;
reset(arg) {

	if(!ob1){
		ob1 = clone_object("players/catwoman/monster/hooker");
		move_object(ob1, this_object());
		}

	if(!ob2){
		ob2 = clone_object("players/catwoman/armor/skirt");
		move_object(ob2, ob1);
		}

     set_light(1);
     if (arg) return;
}

init() {
/*
     add_action("north", "north");

     add_action("south", "south");

     add_action("east", "east");
*/
     add_action("west", "west");
/*
     add_action("up", "up");

     add_action("down", "down");
*/
     add_action("pick", "pick");

   }
pick(){
	write("No stealing!\n");
	return 1;
}
	
/*
north() {
  call_other(this_player(),"move_player", "north#players/catwoman/city/");
  return 1;
}

south() {
  call_other(this_player(),"move_player", "south#players/catwoman/city/");
  return 1;
}

east() {
  call_other(this_player(),"move_player", "east#players/catwoman/city/");
  return 1;
}
*/
west() {
  call_other(this_player(),"move_player", "west#players/catwoman/city/30");
  return 1;
}
/*
up() {
  call_other(this_player(),"move_player", "up#players/catwoman/city/");
  return 1;
}

down() {
  call_other(this_player(),"move_player", "down#players/catwoman/city/");
  return 1;
}
*/
short() { return "Room 6"; }

long() {
 write("Room 6\n");
 write("This is a room in the hotel\n");
 write("     Obvious exit: west\n");
}

realm() { return "NT";}


