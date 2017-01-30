reset(arg) {
     set_light(1);
     if (arg) return;
}

init() {
     add_action("south", "south");
     add_action("jump", "jump");
     add_action("pick", "pick");

   }
pick(){
	write("No stealing!\n");
	return 1;
}
	
south() {
  call_other(this_player(),"move_player", "south#players/catwoman/city/22");
  return 1;
}

jump() {
  this_player()->move_player("jump#players/catwoman/closed/clam.c");
  return 1; }

short() { return "A pirate ship"; }

long() {
 write("A Pirate Ship\n");
  write("This is the bow of the ship.  The water\n"+
	"looks clear and inviting here.  Almost\n"+
	"makes you want to jump in.\n");
 write("     Obvious exit: south\n");
}

realm() { return "NT";}

