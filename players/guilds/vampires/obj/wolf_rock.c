
#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "obj/treasure";
string str;

reset(arg) {
  if(arg) return;
set_id("rock");
set_alias("black rock");
set_short(BOLD+"smooth black rock"+NORM);
set_long(
  "This large, smooth black rock has some lettering etched into its\n"+
  "surface.  It appears to have been placed here with great care.\n");
set_value(0);
set_weight(10000);
}

init() {
  ::init();
  add_action("read_rock","read");
}

read_rock(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "rock" || str == "black rock" || str == "lettering") {
  write("Etched into the surface of this smooth rock is the head\n"+
        "of a snarling wolf.  Underneath this fanged predator are\n"+
        "the words:\n"+BOLD+
        "  He who has the power of wolf summon may\n"+
        "  do so here in this mystical spot."+NORM+"\n");
  return 1; }
}

get() {
  write("It is much too large and heavy for anyone to pick up.\n");
  return; }

