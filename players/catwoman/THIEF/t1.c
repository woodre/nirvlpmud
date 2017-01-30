reset(arg) {




     set_light(1);
     if (arg) return;
}

init() {

     add_action("north", "north");
/*
     add_action("south", "south");

     add_action("east", "east");

*/
     add_action("west", "west");
/*

     add_action("up", "up");

     add_action("down", "down");

     add_action("pick", "pick");
*/
   }
pick(){
	write("No stealing!\n");
	return 1;
}
	

north() {
  call_other(this_player(),"move_player", "north#players/sandman/THIEF/thief_cellar");
  return 1;
}
/*
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
  call_other(this_player(),"move_player", "west#players/catwoman/THIEF/t2");
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
short() { return "Just for thieves *grin*"; }

long() {
 write("Thieves realm entrance\n");
 write("Just for thieves\n");
 write("     Obvious exits: west and north\n");
}

realm() { return "NT";}

