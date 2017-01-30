
reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object lord, key;
   if(!present("ariand")) {
     lord = clone_object("players/molasar/rowan/drake/obj/ariand");
     key = clone_object("obj/treasure");
     key->set_short("A large iron key");
     key->set_value(5);
     key->set_id("key");
     key->set_alias("dungeon_key");
     move_object(key, lord);
     move_object(lord, this_object());
   }
}

realm() { return "NT"; }

id(str) { return str == "bed" || str == "dressers" || str == "couches" ||
                 str == "chairs" || str == "panelling"; }

short() { return "The Governor's Bedchambers"; }

long(str) {
   if(str == "bed") {
     write("A large brass bed with four posts which support a silk\n");
     write("canopy.\n");
     return 1;
   }
   if(str == "dressers") {
     write("You search through some of the dressers but only find some\n");
     write("old clothes.\n");
     return 1;
   }
   if(str == "chairs" || str == "couches") {
     write("You find nothing interesting.\n");
     return 1;
   }
   if(str == "panelling") {
     write("The panelling is made from imported mahogany.\n");
     return 1;
   }
   write("You are in the bedchambers of the Governor of Drakeshore.\n");
   write("A huge canopy bed is next to the eastern wall. Dressers,\n");
   write("couches, and many chairs fill the room. The walls have been\n");
   write("covered in a mahogany panelling.\n");
   write("     There are two obvious exits: west\n");
}

init() {
   add_action("west","west");
}

west() {
   this_player()->move_player("west#"+
                              "players/molasar/rowan/drake/mansion/u_hall2");
   return 1;
}


