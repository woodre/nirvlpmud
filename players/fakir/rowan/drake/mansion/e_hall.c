
int open;

reset(arg) {
   if(!arg)
     set_light(1);
   open = 0;
   extra_reset();
}

extra_reset() {
   object statue;
   int i;

   i = 0;
   while(i < 4) {
     statue = clone_object("players/molasar/rowan/drake/obj/statue");
     statue->set_name("knight");
     statue->set_short("A statue of a knight");
     statue->set_long("A marble statue of a heavily armed knight.\n");
     statue->set_clone_path("players/molasar/rowan/drake/obj/knight");
     move_object(statue, this_object());
     i++;
   }
}

realm() { return "NT"; }

short() { return "Eastern Hallway of the Governor's Manse"; }

long() {
  if(open) {
    write("This long hallway leads to a flight of stairs which go down.\n");
    write("To the west, through an arched doorway, is the Great Hall.\n");
    if(present("statue"))
     write("A pair of statues are positioned on both sides of the stairs.\n");
  } else { 
    write("This long hallway leads to closed door on the south wall.\n");
    write("To the west, through an arched doorway, is the Great Hall.\n");
    if(present("statue"))
     write("A pair of statues are positioned on both sides of the door.\n");
  }
  write("     There are two obvious exits: west and south\n");
}

init() {
   add_action("west","west");
   add_action("down","down");
   add_action("south","south");
   add_action("unlock","unlock");
}

unlock(str) {
   if(!str || str != "door")
     return;
   if(open) {
     write("The door is open!\n");
     return 1;
   }
   if(!present("dungeon_key", this_player())) {
     write("You do not have the right key.\n");
     return 1;
   }
   say(this_player()->query_name()+" unlocks and opens the door.\n");
   write("Ok.\n");
   open = 1;
   return 1;
}

west() {
   this_player()->move_player("west#"+
                              "players/molasar/rowan/drake/mansion/gr_hall");
   return 1;
}

south() {
   if(!open) {
     write("You need to unlock the door first!\n");
     return 1;
   }
   down();
   return 1;
}

down() {
   if(!open)
     return 0;
   if(present("evil_guard")) {
     write("A magic force blocks the stairs.\n");
     return 1;
   }
   write("The stairs curve to the west into a dark room.\n");
   this_player()->move_player("down the stairs#"+
                              "players/molasar/rowan/drake/mansion/dungeon");
   return 1;
}


