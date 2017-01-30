#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_indoors(1);
  set_short("A roadside shrine");
  set_long(
"  This is a roadside shrine to the god of coffee, Maxanez.  In\n\
the center of the shrine is a statue of the deity, and offerings\n\
of coffee beans and low-fat cream substitutes have been placed at\n\
his feet.  You may 'pray' at this shrine if you wish.\n");
  set_dest_dir(0);
  set_items(({
    "statue","Maxanez appears rather short for a god, and wears a wide-\n"+
             "brimmed hat",
  }));
}
void init() {
  ::init();
  add_action("cmd_pray","pray");
}
static int cmd_pray(string str) {
  write("You silently whisper a prayer to Maxanez, the god of coffee.\n");
  say(TPN+" silently whispers a prayer to Maxanez, the god of coffee.\n");
  if(TP->query_intoxination() && TP->query_money() >= 10) {
    TP->add_money(-10);
    TP->add_intoxination(-1);
  }
  return 1;
}
