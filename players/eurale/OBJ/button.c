inherit "obj/armor.c";
#include "/players/eurale/defs.h"

reset(arg) {
  ::reset(arg);
  if (arg) return;

set_name("button");
set_short(HIY+"brass button"+NORM);
set_long(
  "A shiny brass button attached to your clothes.  You can:\n"+
  "  polish - takes you back to the testroom\n"+
  "  heal   - heals 100 can also use 'h'\n"+
  "  snip   - cuts the button off.\n");
set_ac(1);
set_type("misc");
set_weight(0);
set_no_clean(1);
}

drop() { return 1; }

query_auto_load() { return "players/eurale/OBJ/button.c:"; }

init() {
  ::init();
  add_action("polish","polish");
  add_action("snip","snip");
  add_action("heal_me","heal", 1);
}

polish() {
  write("You black out and wake in the testroom..\n");
  TP->move_player("as a tiny bat#players/eurale/testroom.c");
return 1;
}

snip() {
  write("You snip off your brass button and toss it away.\n");
  destruct(TO);
return 1;
}

heal_me() {
  write("You touch the magic button and feel MUCH better....\n");
  TP->heal_self(100);
return 1;
}
