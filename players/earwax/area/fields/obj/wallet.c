#include "../defs.h"

inherit WAXFUNS;
inherit "/obj/treasure.c";

int Value;

void set_money(int arg) { Value = arg; }

void reset(status arg) {

  set_short("A Leather Wallet");
  set_long(line_wrap("This is a wallet that once belonged to a member of the "+ENG+".  You can "+HIW+"empty wallet"+NORM+NORM+" if you wish.\n"));
  set_value(50);
  set_name("leather wallet");
  set_alias("wallet");
  set_weight(1);
}

status get_loot(string arg) {
  object gold;

  if (!arg || arg != "wallet") {
    notify_fail("Empty what? (hint: wallet)\n");
    return 0;
  }

  this_player()->add_money(Value);

  /* Doesn't work right, better way is the above.
  gold = clone_object("/obj/money.c");
  gold->set_money(Value);
  move_object(gold, this_player());
  */

  write("You clean out the wallet and are now "+Value+" coins richer.\n");
  say((string)this_player()->query_name()+" emptys a wallet.\n", this_player());
  destruct(this_object());
  return 1;
}

void init() {
  add_action("get_loot", "empty");
}
