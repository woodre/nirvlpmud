object ob1, ob2;
reset(arg) {
	if(!ob1){
		ob1 = clone_object("players/catwoman/monster/batman");
		move_object(ob1, this_object());
		}
	if(!ob2){
		ob2 = clone_object("players/catwoman/armor/bcape");
		move_object(ob2, ob1);
		}

     set_light(1);
     if (arg) return;
}

init() {

     add_action("north", "north");
     add_action("kiss", "kiss");
/*

     add_action("east", "east");

     add_action("west", "west");

     add_action("up", "up");

     add_action("down", "down");
*/
     add_action("pick", "pick");

   }
pick(){
	write("No stealing!\n");
	return 1;
}
	

north() {
  call_other(this_player(),"move_player", "north#players/catwoman/city/50");
  return 1;
}
kiss() {
  call_other(this_player(),"move_player", "disapears#players/catwoman/closed/gbottle");
  return 1;
}
/*

east() {
  call_other(this_player(),"move_player", "east#players/catwoman/city/");
  return 1;
}

west() {
  call_other(this_player(),"move_player", "west#players/catwoman/city");
  return 1;
}

up() {
  call_other(this_player(),"move_player", "up#players/catwoman/city/");
  return 1;
}

down() {
  call_other(this_player(),"move_player", "down#players/catwoman/city/");
  return 1;
}
*/
short() { return "First Street"; }

long() {
 write("First Street\n");
 write("This is First street to the north is North Ave\n");
 write("     Obvious exit: north\n");
}

realm() { return "NT";}

