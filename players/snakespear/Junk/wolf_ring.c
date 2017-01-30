#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
  set_name("ring");
set_short("A "+BOLD+"Wolfshead"+NORM+" Ring");
set_long(
	"  This ornate ring has the face of a Wolf intricately carved\n"+
	"into it and set in place of the eyes are two sparking "+HIR+"Red\n"+
	"Rubies"+NORM+".  There is an inscription etched into the underside\n"+
	"of the "+BOLD+"black crystal"+NORM+" band you might read.\n");
  set_ac(0);
  set_type("ring");
  set_weight(1);
  set_value(1);
}

init() {
  ::init();
  add_action("check_wear","wear");
  add_action("read","read"); }

read(str) {
  if(str == "inscription") {
  write("The inscription reads... \n"+
	"'Enshrouded within your darkness, my love is forever yours' - Krysta\n");
  return 1; }
}

check_wear(str) {
if(str == "ring" && this_player()->query_real_name() != "snakespear") {
  write("As you slip the ring on your finger the eyes glow a brilliant\n"+
	"red and the ring gives out a HOWL as it disappears....\n");
  say("You watch as the ring is put on...  the eyes begin to glow and\n"+
      "the ring gives out a HOWL and then disappears...\n");
  destruct(this_object());
  return 1; }
return 0;
}
