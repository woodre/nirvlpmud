#include "/players/pestilence/ansi.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("antennae");
  set_alias("antennae");
  set_short(""+HIB+"antennae"+NORM+" from an ant");
  set_long(
"These are the "+HIB+"antennae"+NORM+" broken off from a head of a giant ant.\n"+
"It is possible to find someone to barter these.\n"
  );
  set_weight(2);
  set_value(3500+random(2000));
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
}
