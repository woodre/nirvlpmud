inherit "obj/armor";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("amulet");
  set_type("amulet");
  set_short("A dead black amulet");
  set_long(
"This amulet seems to be made of some kind of dull, black iron, but even\n"+
"though it feels like smooth metal, it doesn't gleam at all.\n"+
"A short leather cord allows it to be worn around the neck, and there\n"+
"seems to be a small inscription on the back.\n");
  set_read("If you be sick of magic...");
  set_class(0);
  set_weight(1);
}
