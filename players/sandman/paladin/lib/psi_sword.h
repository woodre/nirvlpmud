psi_sword() {
   object sword;
   if(this_player()->query_level() < 15) {
       write("You are not experienced enough to cast this spell.\n");
       return 1;
   }
   if(this_player()->query_spell_point() < 75) {
      write("You do not have enough spell points.\n");
      return 1;
   }
   write("You concentrate with all your might, mumbling a soft prayer to\n");
   write("Gil-Estel.\n\n");
   write("A Blinding flash of light stuns you, and with a clap of thunder\n");
   write("A burning blade is in your hand.\n");
   sword = clone_object("players/sandman/WEAPONS/psi_sword");
   move_object(sword, this_player());
   this_player()->add_spell_point(-75);
   return 1;
}
