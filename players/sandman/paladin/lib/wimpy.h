 
/*
 * WIMPY COMMANDS (4/15/94)
 *     wimpyhp()  -  for setting wimpy hp
 *     wimpydir() -  wimpy direction
 * Balowski 950225: Reset wimpydir
 */
 
wimpyhp( str) {
   int wimpy_at;
   if (!str) {
      write(filter_color("Guild wimpy has been turned off.\n",HIG));
      previous_object()->set_wimpy_at(0);
      return 1;
   }
   if (!verify_use())
      return 1;
   if (sscanf(str, "%d", wimpy_at) != 1)
      notify_fail("Usage:  wimpyhp <hit points>");
   previous_object()->set_wimpy_at(wimpy_at);
   write( filter_color( "Guild wimpy has been set at "+wimpy_at+".\n",HIG));
   return 1;
}
 
wimpydir(str) {
   string wimpydir;
   if (!str) {
      write(filter_color("Wimpydir reset. Will retreat headlong.\n",HIG));
      previous_object()->set_wimpydir(0);
      return 1;
   }
/* added by mizan, a quick fix for ppl using wimpydir as a healer command */
  if(str=="n" || str == "s" || str == "w" || str == "e" || str == "u" || str == "d" ||
  str == "nw" || str == "ne" || str == "sw" || str == "se") {
   if (!verify_use())
      return 1;
   if (sscanf(str, "%s", wimpydir) != 1)
      notify_fail("Usage:  wimpydir <direction>");
   previous_object()->set_wimpydir(wimpydir);
   write( filter_color( "Wimpydir set to:  "+wimpydir+"\n",HIG));
   return 1;
  } else {
    write("That is not a valid direction. You must give single\n"+
    "letter arguments like 'n', or 's'.\n");
    return 1;
  }
}
