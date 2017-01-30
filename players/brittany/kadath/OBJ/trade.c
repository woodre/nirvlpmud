#include "/players/feldegast/defines.h"
inherit "/obj/weapon";

reset(arg) {
  if(arg) return;
  set_name("dagger");
  set_alias("knife");
  set_short("Silver Dagger");
  set_long(
"This is a sharp and dangerous dagger made out of a silvery\n"+
"material that gleams in the darkness.  You could probably 'pawn'\n"+
"it for its true value.\n"
  );
  set_weight(3);
  set_class(17);
  set_hit_func(this_object());
  set_value(3500+random(800));
}
init() {
  ::init();
  add_action("cmd_cash","pawn");
}
cmd_cash(str) {
  if(!str || str!="dagger") {
    notify_fail("Pawn what?\n");
    return 0;
  }
  if(!present("pawnbroker",environment(this_player()))) return 0;
  write("The pawnbroker accepts the silver dagger with a gleam in his eye and\n"+
        "gives you "+value+" coins in exchange.\n");
  this_player()->add_money(value);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}

 
