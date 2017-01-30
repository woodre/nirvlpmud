id(str) { return str == "helicopter"; }
short() { return "A helicopter"; }
long() { 
write("A Bell 419 Helicopter designed for transporting people over\n"+
"to the rig.  There is a door that you can enter.\n");
}

init() {
add_action("enter_me","enter");
}

enter_me(str) {
if(!str || str!="helicopter") return 0;
write("You climb into the helicopter.\n");
this_player()->move_player("into the Helicopter#players/mo/rig/ROOMS/oilpad.c");
say(this_player()->query_name()+" leaves into the Helicopter.\n");
  return 1;
}
