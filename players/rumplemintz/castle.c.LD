/*
 * castle.c
 * Rumplemintz@Nirvana
 */

// This is my castle.  It is loaded whenever the mud reboots and will take
// care of adding an exit from DEST to the starting room in my area to
// enable visitors to easily access it

#pragma strong_types

#include <server.h>
#include <is_wizard.h>

#include "inc/rump.h"

#define DEST "/players/rumplemintz/workroom"

// The following class will provide us with a create() function
inherit "basic/create";

// The following is a move hook that checks so that wizards and testplayers
// are the only ones allowed to use the exit 'castle'
status castle_hook() {
  if (!is_wizard(this_player(), IW_TESTPLAYER)) {
    message("You're repelled by a strong magic force.\n");
    return 1;
  }
  return 0;
}

// Yes, the safest place for us to lie is in the NULL. Nobody will randomly
// destruct us there. Thus, we resist being moved anywhere.  You can omit
// this function, I just wanted to point out that castles should no longer
// lie around anywhere
status prevent_move() {
  return 1;
}

// Do nothing other than adding us to the notify server.  Add all rooms, upon
// whose loading or reset you want to be informed.
void create() {
  SE_NOTIFIER->add_notify(DEST);
}

// The following function is called from the notify server whenever a reset
// occured in one of the rooms that we added to the server's notify list in
// create(). The argument 'where' is the load_name() of the room, 'arg' is
// 0 if the room was created or 1 if the room reset

// All the things we want to do in the mud are done here, e.g. adding exits
// to rooms, putting items into other rooms, and so on

// However, is is no longer necessary to put items into rooms for the mere
// reason of providing an entrance to your area.  Everything can be done with
// calling the respective functions in the entrance room(s). You can also
// extend the long description of such rooms, add exits and items there. You
// can even add item actions which depend on fake items of such rooms.

void notify_reset(string where, status arg) {
  switch (where) {
  case DEST:
    if (where->query_exit("castle") != RUMP_ROOMS"entry") {
      where->add_exit(RUMP_ROOMS"entry","castle",#'castle_hook,0,
                      "towards Rumplemintz's castle");
      where->add_extra_long("rump#area_entrance",
                            "The direction 'castle' will take you to "
                            "Rumplemintz's castle area.\n");
      where->add_item("castle","Rumplemintz's castle!\n");
    }
    break;
  }
}

// Make sure that all changes done in the mud are removed when our castle is
// destructed and thus taken out of the game

void notify_destruct() {
  DEST->remove_exit("castle");
  DEST->remove_extra_long("rump#area_entrance");
  DEST->remove_item("castle");
}

