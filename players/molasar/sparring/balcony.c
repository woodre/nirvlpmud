
/*
 * BALCONY (7/3/94)
 * This is were the people may view a sparring match
 */

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "Balcony overlooking the Sparring Arena"; }

long() {
   write("You are in the balcony overlooking the Sparring Arena.\n");
   write("Numerous benches and seats cover every inch of the balcony,\n");
   write("providing seating for hundreds of spectators. A large metal\n");
   write("rail runs along the edge of the balcony preventing any over-\n");
   write("zealous fans from falling into the arena.\n");
   write("     There are two obvious exits: down\n");
}

init() {
   add_action("down","down");
}

down() {
   this_player()->move_player("down the marble staircase"+
       "#players/molasar/sparring/hall");
   return 1;
}

