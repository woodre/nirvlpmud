tap(str) {
   object who;
   string option;

   if ( (!str) || (sscanf(str,"%s %s",bugged,option) != 2) || ( (option != "on") && (option != "off") ) ) {
   write("Usage: tap [player] [on/off].\n");
   return 1;
   }
   who = find_player(bugged);
   if (!who) {
      write(capitalize(bugged)+" is not logged on at this time.\n");
      return 1;
      }
   if (option=="on") {
      if (bug) {
         write("You're BUGGING enough people already! ;)\n");
         return 1;
         }
      bug = clone_object("/players/dodger/closed/bug");
      move_object(bug,environment(who));
      write(capitalize(bugged)+" is now tapped.  Fear Watergate.\n");
      }
   if (option=="off") {
      if (!bug) {
         write(capitalize(bugged)+" is not bugged!\n");
         return 1;
         }
      destruct(bug);
      write(capitalize(bugged)+" is now untapped.\n");
      }

   return 1;

}
