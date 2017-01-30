inherit "obj/money";

get() {
   if (this_player()->query_level()> 3) {
write(
   "A magical force holds the coins down!\n"+
   "\n"+
   "A soothing voice from above speaks:\n"+
   "\n"+
   "     Sorry, but I made this money so that novices and other\n"+
   "lower level players could get some kind of financial start.\n"+
   "Please help new players get accustomed to the game.\n"+
   "Thank you for your cooperation - Rump!\n"
);
return 0;
   }
   if (this_player()->query_gold() > 500) {
      write("A magical force holds the coins down!\n\n");
      write("A soothing voice from above speaks:\n");
      write("Sorry, but I made this money for poor players.\n");
      write("You seem to have enough money now.  Please tell\n");
      write("some poor soul about this location so that he/she\n");
      write("may benefit.  Thank you - Rump!\n");
      return 0;
   }
   write("Suddenly, you hear a soothing voice from above:\n");
   write("Welcome adventurer!  This money was put here\n");
   write("to help you obtain a financial basis.  Spend it well!\n");
   write("Have fun! - Rump!\n");
   return(::get());
}
