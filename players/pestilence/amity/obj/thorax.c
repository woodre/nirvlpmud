#include "/players/pestilence/ansi.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("thorax");
  set_alias("thorax");
  set_short(""+HIB+"thorax"+NORM+" from an ant");
  set_long(
"This is the "+HIB+"thorax"+NORM+" from a giant ant.  This is a piece of the ant's\n"+
"body and it is very large.\n"
  );
  set_weight(2);
  set_value(3000+random(3000));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("mr. duke",environment(this_player()))) {
      write("Mr. Duke says: Wow I'm glad to see this, this means\n"+
            "there are less ants to worry about, Thank you!\n"+
            "Mr. Duke says: I'll give you "+value+" coins for it.\n");
      this_player()->add_money(value);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
