
reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object statue;
   int i;

   i = 0;
   while(i < 4) {
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

short() { return "Dungeon below the Governor's Manse"; }

long() {
   write("You have entered the dungeons below the Governor's Manse.\n");
   write("Cold grey stones give the room a gloomy and depressing feel.\n");
   write("Three small open cells lie off from this main room. No doors or\n");
   write("bars are apparent.\n");
   write("     There are four obvious exits: north, south, west, and up\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
   add_action("west","west");
   add_action("up","up");
}

north() {
   if(present("evil_guard")) {
     write("A magical force bars the cell.\n");
     return 1;
   }
   this_player()->move_player("north#"+
                              "players/molasar/rowan/drake/mansion/cell1");
   return 1;
}

south() {
   if(present("evil_guard")) {
     write("A magical force bars the cell.\n");
     return 1;
   }
   this_player()->move_player("south#"+
                              "players/molasar/rowan/drake/mansion/cell3");
   return 1;
}

west() {
   if(present("evil_guard")) {
     write("A magical force bars the cell.\n");
     return 1;
   }
   this_player()->move_player("west#"+
                              "players/molasar/rowan/drake/mansion/cell2");
   return 1;
}

up() {
   write("Halfway up the stairs curve to the north.\n");
   this_player()->move_player("up the stairs#"+
                               "players/molasar/rowan/drake/mansion/e_hall");
   return 1;
}


