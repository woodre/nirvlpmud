/*****************************************************************************


  This is just the facade to a castle. If you want to enable the
  "enter" command, move the player to a room which you have to
  design yourself.

  This file is loaded automatically from "init_file". We have to move
  ourself to where we are supposed to be. Do this by changing the
  destination of move_object in create().

  This file uses two elementary and important mudlib-features, these
  are /basic/parser and /basic/message. You are supposed to use these as
  well. Read /doc/build/parser and /doc/build/messages for documentation.

*****************************************************************************/

#include <prop/item.h>
#include <grammar.h>
#include <message.h>

inherit "/complex/item";
inherit "/basic/parser";
inherit "/basic/message";

void create() {
  set_property(P_NOT_PORTABLE);
  set_id(({ "castle", "castle of Example" }));
  set_short("castle of Example");
  set_long("\
This is the castle of Example.\n\
Example is a rather new domain, but it is an amazing castle just the\n\
same. However, the gates are closed.\n");
  add_rule("enter <me>", "enter");
  add_error_message("enter", "What do you want to enter?\n");
  move_object(this_object(), "/room/new_castles");
}

void init() {
  add_actions();
}

status do_action(string verb, mapping args) {
  switch(verb) {
  case "enter":
    message(({
      ({ M_PLAYER, M_PL_VERB, ({ " try", " tries" }), " to enter ",
         M_ME_THE, " but ", M_PL_VERB, "fail", " because that's not an ",
         "open castle." })
    }));
    return 1;
    break;
  default:
    return 0;
    break;
  }
}

#if 0
/*****************************************************************************

  Above you read the classical version of a castle. But as the castle's purpose
  is to be an entrance to the wizard's area, an easier version of the castle
  can be used very often. Such a version could look like the lines below:

inherit "/basic/create";

void create() {
  move_object(this_object(), "/room/nobody_knows_where");
  environment()->add_item("path", "It is overgrown with weeds.\n");
  environment()->add_exit("/players/somebody/start", "south");
}

string extra_long() {
  return "A path leads south into a dense forest.\n";
}

*****************************************************************************/
#endif

