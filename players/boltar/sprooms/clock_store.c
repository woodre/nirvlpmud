id(str) { return str == "shop"; }
init() {
      add_action("northwest"); add_verb("northwest");
      add_action("south"); add_verb("south");
      add_action("buy"); add_verb("buy");
  set_light( 1);
}
 short() { return "There is a time piece store to the northwest (nw).";}
long() {
   write("The time piece shop has some very nice display models in the glass\n"+
   "case before you.  You may buy a watch for the low price of 50 gold coins.\n"+
   "The time pieces are accurate to for the central time zone.  To set the\n"+
   "watch for another time zone, just use 'zone #' where # is a positive\n"+
   "or negative number of hours to make the time correct for you.  Each watch\n"+
   "has an hourly chime, to alert you to what time it is.\n"+
   "You may purchase a watch with the command 'buy watch'\n"+
   "The exit of the shop is the south.\n");
}
 northwest() {
 call_other(this_player(), "move_player", "into shop#players/boltar/sprooms/clock_store.c");
  call_other(this_object(), "long", 0);
   return 1;
}
south() {
  call_other(this_player(), "move_player", "leaves the store#room/forest8.c");
  return 1;
}
buy(str) {
  object watch;
   if (str != "watch") {
    return 1;
  }
   watch = clone_object("players/boltar/things/watch.c");
   move_object(watch, this_player());
   call_other(this_player(), "add_money", -50);
   write("You have bought an excelent time piece.\n");
   return 1;
}
