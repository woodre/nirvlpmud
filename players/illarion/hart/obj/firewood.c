#include "/players/illarion/dfns.h"
inherit "obj/treasure";


query_weight() { return 1; }
int id(string str) { return
  (str== "wood" || str == "firewood");
}
string short() {
  return "A pile of firewood";
}
void long() {
  write("A neatly-stacked pile of firewood, enough to keep a well-tended\n"+
        "fire going for several hours.\n");
}
