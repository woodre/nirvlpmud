#include "defs.h"

inherit "/obj/treasure.c";

string tablet;
int found;

void reset(int arg) {
  if(arg) return;
  set_id("rubble");
  set_short("A pile of rubble");
  set_long(
    "This is a pile of rocks and rubble strewn about the plaza.\n"
  );
  set_weight(50);
}
get() { return 0; }

void init() {
  add_action("cmd_search","search");
}

int cmd_search(string str) {
  if(!str || !id(str)) {
    notify_fail("Search what?\n");
    return 0;
  }
  if(found) {
    write("You find nothing in the rubble.\n");
    return 1;
  }
  write("You find a large glowing gem and the fragment of a tablet\n"+
        "amongst the pieces of rubble.\n");
  found=1;
  move_object(clone_object(OBJ_PATH+"heartstone.c"),this_player());
/* For quest
  move_object(clone_object(tablet),this_player());
*/
  TP->recalc_carry();
  return 1;
}

void set_tablet(string str) {
  tablet=str;
}
