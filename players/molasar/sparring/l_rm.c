
/*
 * LOSERS ROOM (2/6/94)
 * This is were the loser is transported after the sparring match
 */

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "A resting room"; }

long() {
   write("You are in a resting room.\n");
   write("You may return to the Sparring Hall or the Village Church.\n");
   write("     There are two obvious exits:  hall, church\n");
}

init() {
   calm();
   add_action("hall","hall");
   add_action("church","church");
}

hall() {
   this_player()->move_player("for the Hall#players/molasar/sparring/hall");
   return 1;
}

church() {
   this_player()->move_player("for the church#room/church");
   return 1;
}

calm() {
   if(this_player() && query_ip_number(this_player())) {
     this_player()->stop_fight();
     command("stop", this_player());
   }
}

exit() {
   if(this_player() && this_player()->query_attack())
     this_player()->stop_fight();
}

