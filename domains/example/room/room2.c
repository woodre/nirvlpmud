/*  the other side of the door from room 1 */

#include <exits.h>    // for macro EXIT_VISIBLE_IF_OPEN
#include <names.h>    // for property macros
#include <message.h>  // for message macros
#include <grammar.h>  // for parser macros like <me>

inherit "complex/room";

void configure() {
  set_short("in the sleeping room");
  set_long("Finally you have found the sleeping room.\n");
  set_items(({
    ({ "room", "sleeping room" }), "Such rooms are good for sleeping.\n",
  }));
  set_property(P_INSIDE);
}

status key_test(object key, object what) {
  if (program_name(key) == "/domains/example/keys/key_example")
    return 1;
}

void populate() {
  object d2;

  if (!present("south door")) {
    d2 = clone_object("/complex/new_door");
    move_object(d2, this_object()); // first move the door, then set it's
                                    // attributes
    d2->set_door_exit("/domains/example/room/room1", "south", 0,
                      EXIT_VISIBLE_IF_OPEN, "towards the other side");
/* the door leads south to /domains/example/room/room2 without a move-hook (0)
 * and the exit is only visible if the door is opened. The displayed message
 * while passing the door is 'Rumpy leaves towards the other side.'
 */
    d2->set_door_short("a philosophical door");
    d2->set_door_long("The door should always have a nice story for you.\n");
/* never use set_short or set_long in the door, because you'll overwrite
 * important information situated there.
 */
    d2->set_name("philosophical door");
    d2->set_id(({ "door", "south door", "southern door",
                  "philosophical door" }));
    d2->set_open_text((({
      ({ "The philosophical door says: 'To open or not to open, ",
         "that would be no question.' and opens for ", M_PLAYER, "." })
    })));
    d2->set_close_text((({
      ({ "The philosophical door thinks: 'The closed state doesn't accept "
         "escapers.' and closes for ", M_PLAYER, "." })
    })));
    d2->set_unlock_text((({
      ({ "The philosophical door laughs hysterically as ", M_PLAYER,
         M_PL_VERB, " unlock", " it." })
    })));
    d2->set_lock_text((({
      ({ "The philosophical door hmms thoughtfully as ", M_PLAYER, M_PL_VERB,
         " lock", " it again." })
    })));
/* These texts will be displayed instead of the standard messages 'You open
 * the door.' or 'Rumpy locks the door.'.
 */
    d2->set_default_open(0); // door will shut after awhile again, if it was
                             // open
    d2->set_default_locked(1); // door is locked after awhile again, if it
                               // was unlocked
    d2->set_key_test_function(#'key_test); // will check the correct key for
                                           // this door
  }
  if (!present_clone("domains/example/mon/eumel", this_object()))
    move_object(clone_object("domains/example/mon/eumel"), this_object());
    // If eumel isn't here, then put it here
}

