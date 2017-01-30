
reset(arg) {
   if(!arg)
     set_light(1);
}

realm() { return "NT"; }

short() { return "Upper Hall of the Governor's Manse"; }

long() {
   write("To the east two giant double doors are open which lead into\n");
   write("the bedchambers of the Governor of Drakeshore.\n");
   write("     There are two obvious exits:  east and west\n");
}

init() {
   add_action("east","east");
   add_action("west","west");
}

east() {
   this_player()->move_player("east#"+
                              "players/molasar/rowan/drake/mansion/bedroom");
   return 1;
}

west() {
   this_player()->move_player("west#"+
                              "players/molasar/rowan/drake/mansion/u_hall1");
   return 1;
}



