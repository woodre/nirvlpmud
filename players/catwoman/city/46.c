object ob1, ob2;
reset(arg) {
	if(!ob1){
		ob1 = clone_object("players/catwoman/monster/worker");
		move_object(ob1, this_object());
		}
	if(!ob2){
		ob2 = clone_object("players/catwoman/armor/hardhat");
		move_object(ob2, ob1);
		}

     set_light(1);
     if (arg) return;
}

init() {
/*
     add_action("north", "north");
*/
     add_action("south", "south");
     add_action("east", "east");

/*
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
	
/*
north() {
  call_other(this_player(),"move_player", "north#players/catwoman/city/");
  return 1;
}
*/
south() {
  call_other(this_player(),"move_player", "south#players/catwoman/city/45");
  return 1;
}

east() {
if(present("worker")) {
  write("The worker hollars at you, 'Can't you see we're working here?'\n");
  return 1; }
else {
  this_player()->move_player("east#/players/catwoman/city/18.c");
  return 1; }
}

/*
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
short() { return "Under construction"; }

long() {
 write("Under construction\n");
  write("This area has some construction going on.  To the\n"+
	"south is North Ave and to the east is the Metropolis\n"+
	"Hotel.\n");
  write("	Obvious exits:  south, east\n");
}

realm() { return "NT";}


