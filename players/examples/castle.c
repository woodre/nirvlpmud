/*
 * castle.c
 * Rumplemintz@Nirvana
 */

// This is the castle of the example area. It is loaded whenever the mud
// reboots and will take care of adding an exit from /room/adv_wizard to
// /players/examples/room/start to enable visitors to easily access the area.

#pragma strong_types

#include <server.h>
#include <is_wizard.h>

#include "inc/examples.h"

#define DEST "room/adv_wizard"

// The following class will provide us with a create() function.

inherit "basic/create";

// This following function is the move hook which checks that only wizards
// and testplayers can use the exit 'examples'.

status
examples_hook() {
  if (!is_wizard(this_player(), IW_TESTPLAYER)) {
    message("You're repelled by a strong magic force.\n");
    return 1;
  }
  return 0;
}

// Yes, the safest place for us to lie in the NULL.  Nobody will randomly
// destruct us there.  Thus, we resist to be moved anywhere.  You can omit
// this function, I just wanted to point out that castles should no longer
// lie around anywhere.

status
prevent_move() {
  return 1;
}

// Do nothing other than adding us to the notify server.  Add all rooms, upon
// whose loading or reset you want to be informed.

void
create() {
  SE_NOTIFIER->add_notify(DEST);
}

// The following function is called from the notify server whenever a reset
// occured in one of the rooms that we added to the server's notify list in
// create().  The argument 'where' is the load_name() of the room, 'arg' is
// 0 if the room was created or 1 if the room resetted.

// All the things we want to do in the mud are done here, e.g. adding exits
// to rooms, putting items into other rooms, and so on.

// However, it is no longer necessary to put items into rooms for the mere
// reason of providing an entrance to your area.  Everything can be done with
// calling the respective functions in the entrance room(s).  You can also
// extend the long description of such rooms, add exits and items there.  You
// can even add item actions which depend on fake items of such rooms.

void
notify_reset(string where, status arg) {
  switch (where) {
    case DEST:
      if (where->query_exit("examples") != EXAMPLES_ROOMS"start") {
        where->add_exit(EXAMPLES_ROOMS"start", "examples", #'examples_hook,0,
                        "towards the LPC examples");
        where->add_extra_long("examples#area_entrance",
                              "The direction 'examples' will take you to some "
                              "rooms with fine LPC-examples.\n");
        where->add_item("examples","Yeah, just head 'examples' and study our "
                        "fine LPC examples.\n");
      }
      break;
  }
}

// Make sure that all changes done in the mud are removed when our castle is
// destructed and thus taken out of the game.

void
notify_destruct() {
  DEST->remove_exit("examples");
  DEST->remove_extra_long("examples#area_entrance");
  DEST->remove_item("examples");
}

