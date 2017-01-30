
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
   statue = clone_object("players/molasar/rowan/drake/obj/statue");
   statue->set_name("mage");
   statue->set_short("A statue of a mage");
   statue->set_long("A marble statue of a mage posed for spellcasting.\n");
   statue->set_clone_path("players/molasar/rowan/drake/obj/mage");
   move_object(statue, this_object());
}

realm() { return "NT"; }

id(str) { return str == "chandelier" || str == "tapestries" ||
                 str == "murals" || str == "crossbeam"; }

short() { return "The Foyer of the Governor's Manse"; }

long(str) {
   if(str == "chandelier") {
     write("It is perhaps the most magnificent chandelier you've ever\n");
     write("seen. Three glass globes, each with some of light inside,\n");
     write("is suspended from a brass support. The globes are etched\n");
     write("with pictures of people, animals, and houses, and stained\n");
     write("with many different colors. The light and the slow twirling\n");
     write("of the globes gives the illusion that the figures are moving.\n");
     return 1;
   }
   if(str == "tapestries" || str == "murals") {
     write("The pictures depicted on the murals and tapestries range from\n");
     write("normal life to large-scale warfare.\n");
     return 1;
   }
   if(str == "crossbeam") {
     write("A wooden beam, just lower than the ceiling, which acts as the\n");
     write("mounting for the chandelier.\n");
     return 1;
   }
   write("You have entered the foyer of the Governor's Manse.\n");
   write("The room is elaborately decorated with tapestries and murals\n");
   write("from all corners of the realm. A large glass chandelier is\n");
   write("suspended from a large wooden crossbeam in the exact center of\n");
   write("the room. An arched doorway to the north leads into the Great\n");
   write("Hall of the Manse.\n");
   write("     There are two obvious exits: north and south\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
}

north() {
   this_player()->move_player("north#"+
                              "players/molasar/rowan/drake/mansion/gr_hall");
   return 1;
}

south() {
   if(present("evil_guard")) {
     write("A magical force bars the exit.\n");
     return 1;
   }
   this_player()->move_player("south#"+
                              "players/molasar/rowan/drake/mansion/path");
   return 1;
}



