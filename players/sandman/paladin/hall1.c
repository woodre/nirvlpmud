

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
   write("   north - Grand Hall\n");
   write("   south - Paladin Entry\n");
   write("   east  - Training and Advancement Center\n");
   write("   west  - Meeting Hall\n");
   write("   portal- Alliance room\n");
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
   add_action("portal","portal");
}

north() {
   this_player()->move_player("north#players/sandman/paladin/hall2");
   return 1;
}

south() {
   this_player()->move_player("south#players/sandman/paladin/entry");
   return 1;
}

east() {
   this_player()->move_player("east#players/sandman/paladin/adv_guild");
   return 1;
}

west() {
   write("The meeting hall is still under construction.\n");
   return 1;
   this_player()->move_player("west#players/sandman/paladin/mt_hall");
   return 1;
}

portal() {
   this_player()->move_player("through a portal#"+
                      "players/saber/closed/bards/bardrooms/alliance");
   return 1;
}

