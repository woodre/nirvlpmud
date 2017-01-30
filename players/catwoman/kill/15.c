inherit "/room/room.c";
reset(arg) {
     set_light(0);
     if (arg) return;
}

exit(){if(this_player())this_player()->clear_fight_area();}
init() {
     ::init();this_player()->set_fight_area();

     add_action("block", "north");
     add_action("south", "south");
     add_action("east", "east");
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
  call_other(this_player(),"move_player", "north#players/catwoman/kill/4");
  return 1;
}

south() {
  call_other(this_player(),"move_player", "south#players/catwoman/kill/19");
  return 1;
}

east() {
  call_other(this_player(),"move_player", "east#players/catwoman/kill/16");
  return 1;
}

west() {
  call_other(this_player(),"move_player", "west#players/catwoman/kill/14");
  return 1;
}
block(){
  write("You run SMACK into the wall.\n");
  return 1;
}
/*
up() {
  call_other(this_player(),"move_player", "up#players/catwoman/kill/");
  return 1;
}

down() {
  call_other(this_player(),"move_player", "down#players/catwoman/kill/");
  return 1;
}
*/
short() { return "A dark room"; }

long() {
write("A labyrinth of tunnels.\n  Blood stained stone walls. The stench of death in the air.\n  You hear something in the darkness.\nthere is darkness to the north, south, east and west.\n");
 
}

