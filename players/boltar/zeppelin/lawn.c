id(str) { return str == "lawn"; }
init() {
      add_action("southeast","southeast");
}
short() { return "There is a large open green lawn to the southeast"; }
long() {
    write("You can see a large cigar shaped object floating just above the\n"+
     "lawn, held down by lines tied to towers.\n");
}
 southeast() {
 call_other(this_player(), "move_player", "south#players/boltar/zeppelin/landing.c");
   return 1;
}
