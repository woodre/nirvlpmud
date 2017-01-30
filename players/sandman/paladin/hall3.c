

realm() { return "NT"; }

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The Grand Hall"; }

long() {
   write("You are in the Grand Hall of the Paladins Guild.\n");
   write("The hallway can easily fit twenty men standing abreast.\n");
   write("The walls and flooring have been covered in grey and white\n");
   write("marble. Numerous tapestries hang from the walls showing\n");
   write("pictures of knights and paladins in battle; some in sparring\n"); 
   write("matches, and others battling great dragons and hordes of\n");
   write("invaders of every type and desription imaginable.\n");
   write("EXITS:\n");
   write("   north - Practice Hall\n");
   write("   south - Grand Hall\n");
   write("   east  - Under construction\n");
   write("   west  - Expeditions Outfiters Inc.\n");
}

init() {
   if(!present("guild_medal", this_player()) &&
       this_player()->query_interactive()) {
      call_other(this_player(), "move_player", "out#room/church");
      return 1;
   }
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("west","west");
}

north() {
   this_player()->move_player("north#players/sandman/paladin/practice/hall");
   return 1;
}

south() {
   this_player()->move_player("south#players/sandman/paladin/hall2");
   return 1;
}

east() {
   write("The area to the east is still under construction.\n");
   return 1;
}

west() {
   this_player()->move_player("west#players/sandman/paladin/hshop");
   return 1;
}

