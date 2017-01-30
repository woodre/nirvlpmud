/*
 * butz.c
 * Rumplemintz@Nirvana
 */

/*
 * Main intention of this file:
 *
 * - a further example for the usage of basic/parser in items
 *
 * If you aren't familiar with the parser you should study the file
 * players/examples/obj/bu.c in detail.
 *
 */

#pragma strong_types

#include "../inc/examples.h"

inherit "basic/parser";
inherit "complex/item";

void
configure() {
  item::configure();
  set_id("butz");
  set_short("a butz");
  set_long("This is a butz, another ingredient to the butzmutznutzrutzfutz. "
           "Special about this butz is that you could disconnect it.\n");
  set_encumbrance(1000);
  set_value(10);
  add_rule("disconnect "G_ME, "disconnect");
  add_error_message("disconnect", "What do you want to disconnect?\n");
}

void
init() {
  item::init();
  add_actions();
}

status
do_action(string verb, mapping args) {
  object ob;

  switch (verb) {
  case "disconnect":
    message(({
      ({ M_PL_THE, M_PL_VERB, "disconnect", M_ME_THE, "." }),
      ({ M_WRITE, "You now have a bu and a tz." })
    }));
    if (transfer(ob = clone_object(EXAMPLES_OBJ"bu"), this_player()))
      move_object(ob, environment(this_player()));
    if (transfer(ob = clone_object(EXAMPLES_OBJ"bu"), this_player()))
      move_object(ob, environment(this_player()));
    ob->set_tz();
    destruct(this_object());
    return 1;
  default:
    return 0;
  }
  NO_WARN_MISSING_RETURN;
}
