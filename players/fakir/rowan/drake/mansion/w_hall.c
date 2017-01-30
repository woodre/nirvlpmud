
reset(arg) {
   if(!arg)
     set_light(1);
}

realm() { return "NT"; }

short() { return "Eastern Hall of the Governor's Manse"; }

long() {
   write("Stairs lead up from the western end of the hall.\n");
   write("The Great Hall of the mansion is east of here.\n");
   write("     There are two obvious exits: east and up\n");
}

init() {
   add_action("east","east");
   add_action("up","up");
}

east() {
   this_player()->move_player("east#"+
                              "players/molasar/rowan/drake/mansion/gr_hall");
   return 1;
}

up() {
   this_player()->move_player("up#"+
                              "players/molasar/rowan/drake/mansion/u_hall1");
   return 1;
}



