inherit "room/room";
init() {
    add_action("southeast","southeast");
    add_action("RUSH","RUSH");
    add_action("join","join");
}
reset(arg) {
      if (arg) return;
          short_desc="R.U.S.H. headquarters";
          long_desc="This is the Headquarters for R.U.S.H.\n" +
                    "Really\n" +
                    "Underrated by\n" +
                    "So many\n" +
                    "Hypocrites\n" +
                    "This is where you can go to get away from\n" +
                    "The evil liberal influence.\n" +
                    "Also, you may be a card carrying R.U.S.H.\n" +
                    "member by typing join.  You can be in a guild and\n" +
                    "still have this.  For a list of commands used with\n" +
                    "R.U.S.H., type in 'RUSH'.\n" +
                    "There is one exit to the southeast.\n";
}
southeast() {
   call_other(this_player(),"move_player","southeast#players/haji/rush/ny/wstreet2");
   return 1;
   }
join() {
    write("The guidlines for R.U.S.H. are still be decided try back later.\n");
    return 1;
}
RUSH() {
    join();
    return 1;
}
