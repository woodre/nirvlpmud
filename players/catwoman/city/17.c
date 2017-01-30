/*object ob1, ob2;*/
reset(arg) {
/*for cloning monster etc*****
	if(!ob1){
		ob1 = clone_object("players/catwoman/monster");
		move_object(ob1, this_object());
		}
	if(!ob2){
		ob2 = clone_object("players/catwoman/weapon");
		move_object(ob2, ob1);
		}
*/
     set_light(1);
     if (arg) return;
}

init() {

     add_action("north", "north");

     add_action("south", "south");
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
  call_other(this_player(),"move_player", "north#players/catwoman/city/43");
  return 1;
}

south() {
  call_other(this_player(),"move_player", "south#players/catwoman/city/16");
  return 1;
}
/*
east() {
  call_other(this_player(),"move_player", "east#players/catwoman/city/");
  return 1;
}
*/
west() {
  this_player()->move_player("west#players/catwoman/hall.c");
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
short() { return "The Boardwalk"; }

long() {
 write("BoardWalk\n");
 write("This is street goes along the coast of Metropolis\n");
  write("to the south is a dock and Main street.\n");
 write("     Obvious exits: north, south.\n");
}

realm() { return "NT";}

