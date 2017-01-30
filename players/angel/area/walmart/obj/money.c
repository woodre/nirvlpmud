#include <ansi.h>

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("walmart gift card");
  set_alias("card");
  set_short("A Wal-Mart gift card");
  set_long(
"This is a Wal-Mart gift card with a sizeable balance.\n\
the gift card can be 'refund'ed for the coin value at\n\
the checkouts.\n"
  );
  set_weight(1);
  set_value(50);
}

init() {
  add_action("cmd_barter","refund");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("bob",environment(this_player()))) {
      write("Bob says, congratulations on the kill!\n");
      this_player()->add_money(1000 + random (500));
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("exchange what?\n");
}