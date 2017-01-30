/*  This is an example for complex/door and for the parser-
 *  function add_item_action, which should be preferably used
 *  in rooms if the action includes a fake-item. it's better than
 *  an add_rule and easier to handle.
 */

#include <exits.h>    // for macro EXIT_VISIBLE_IF_OPEN
#include <names.h>    // for property macros
#include <message.h>  // for message macros
#include <grammar.h>  // for parser macros like <me>

inherit "complex/room";  // standard class for rooms

status key;

mixed punch_ball() {
  if (key) {
    move_object(clone_object("/domains/example/keys/key_example"),
                this_object());
    key=0;  // only one key per reset please;
    return ({({ M_PLAYER, M_PL_VERB, " punch", " the punching ball. It swings ",
                "around and suddenly a key bangs against ", M_PLAYER_S,
                " head." })});
  }
  return ({({ M_PLAYER, M_PL_VERB, " punch", " the punching ball. It swings ",
              "back and again forwards, just to hit ", M_PLAYER,
              " on the head." })});
}

void configure() {  // configure the room
  set_short("in a training room");
  set_long("Here we have a training room, unfortunately it's empty but\n"
   "a punching ball in the center of the room cries for attention.\n");
  set_items(({
    ({ "ball","punching ball" }),
       "A ball for punching it.\n",
    ({ "room","training room","center","attention" }),
       "All in all a useful noun to describe something.\n"
  }));
  set_exits(({"./meadow" }),({ "east" }),({ 0 }),({ 0 }),({ "east" }) );
  add_item_action(({"ball","punching ball"}),"punch <me>","punch",#'punch_ball);
  set_property( P_INSIDE );  // this room isn't on fresh air
}

status key_test(object key, object what) {  // checks whether the correct key
                                            // is used
  if (program_name(key) == "/domains/example/keys/key_example")
    return 1;
}

void populate() {
  object d2;

  key=1;

  if (!present("north door")) {
    d2=CO("/complex/new_door");
    MO(d2,TO);  // first move the door, then set it's attributes;

    d2->set_door_exit("/domains/example/room/room2","north",0,
                      EXIT_VISIBLE_IF_OPEN,"towards the other side");
/*  the door leads north to /domains/example/room2 without a move-hook (0) and
 *  the exit is only visible if the door is opened. the displayed message while
 *  passing the door is 'Doro leaves towards the other side.'
 */
    d2->set_door_short("a philosophical door"); 
    d2->set_door_long("The door should always have a nice story for you.\n");
/*  never use set_short or set_long in the door, because you'll overwrite
 *  important information situated there.
 */
    d2->set_name("philosophical door");
    d2->set_id(({"door","north door","northern door","philosophical door"}));

    d2->set_open_text((({
      ({ "The philosophical door says: 'To open or not to open, ",
         "that would be no question.' and opens for ", M_PLAYER, "." })
    })));
    d2->set_close_text((({
      ({ "The philosophical door thinks: 'The closed state doesn't "
         "accept escapers.' and closes for ", M_PLAYER, "." })
    })));
    d2->set_unlock_text((({
      ({ "The philosophical door laughs hysterically as ", M_PLAYER,
         M_PL_VERB, " unlock", " it." })
    })));
    d2->set_lock_text((({
      ({ "The philosophical door hmms thoughtfully as ", M_PLAYER, M_PL_VERB,
         " lock"," it again." })
    })));
/*  These texts will displayed instead of the standard-messages 'You open
 *  the door.' or 'Rumpy locks the door.'.
 */
    d2->set_default_open(0);  // door will shut after a while again, if it
                              // was opened
    d2->set_default_locked(1);  // door is locked after a while again, if it
                                // was unlocked
    d2->set_key_test_function(#'key_test);  // will check the correct key for
                                            // this door
  }
  if (!present("cat"))
    move_object(clone_object("domains/example/mon/cat"), this_object());
}

