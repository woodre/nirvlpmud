
reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object statue;
   int i;

   i = 0;
   while(i < 2) {
     statue = clone_object("players/molasar/rowan/drake/obj/statue");
     statue->set_name("knight");
     statue->set_short("A statue of a knight");
     statue->set_long("A marble statue of a heavily armed knight.\n");
     statue->set_clone_path("players/molasar/rowan/drake/obj/knight");
     move_object(statue, this_object());
     i++;
   }
   i = 0;
   while(i < 2) {
     statue = clone_object("players/molasar/rowan/drake/obj/statue");
     statue->set_name("mage");
     statue->set_short("A statue of a mage");
     statue->set_long("A marble statue of a mage posed for spellcasting.\n");
     statue->set_clone_path("players/molasar/rowan/drake/obj/mage");
     move_object(statue, this_object());
     i++;
   }
}

realm() { return "NT"; }


short() { return "Upper Hall of the Governor's Manse"; }

long() {
   write("Stairs lead down to the west while the hall continues east.\n");
   if(present("statue")) 
     write("A pair of statues are positioned on both sides of the stairs.\n");
   write("     There are two obvious exits: east and down\n");
}

init() {
   add_action("east","east");
   add_action("down","down");
}

east() {
   this_player()->move_player("east#"+
                              "players/molasar/rowan/drake/mansion/u_hall2");
   return 1;
}

down() {
   if(present("evil_guard")) {
     write("A magical force bars the exit.\n");
     return 1;
   }
   this_player()->move_player("down#"+
                              "players/molasar/rowan/drake/mansion/w_hall");
   return 1;
}



