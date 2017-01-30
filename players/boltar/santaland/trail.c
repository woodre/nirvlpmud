id(str) { return str == "trail"; }
init() {
  add_action("north", "north");
}
 short() { return "The trail to Santa's workshop is north"; }
long() {
    write("As you look down the trail you see snow in the distance and a\n"+
    "small wooden building.  Everthing there looks happy and cheerful, unlike\n"+
    "the gloomy, run down Big House.  If Santa really lives, he must live \n"+
    "in a place like the one down the trail.\n");
}
 north() {
   write("As you move north, you feel very relaxed, as though all your fears and worries\n" +
  "have been lifted.\n");
 call_other(this_player(), "move_player", "down the trail#players/boltar/santaland/snow1.c");
   return 1;
}
is_castle() {return 1;}
