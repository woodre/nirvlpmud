/*****************************************************************************
  Example for the use of fake_itmes and something to allow sitting and lying
  down on. Also show the usage of closures for changing descriptions.
*****************************************************************************/

#pragma strong_types

#include <message.h>
#include <grammar.h>
#include <prop/room.h>

inherit "/complex/room";

int flowers_left;

string room_long() {
  /* This is the function called by the closure for the long-description of
   * the room
   */
  return
    "You are on a beautiful meadow. The grass below your feet is soft and\n" +
    "invites you to lie or sit down and relax for awhile.\n" +
    (flowers_left ? "There are some flowers growing on the meadow.\n" : "" );
}

string meadow_long() {
  /* This is the function called by the closure for the long-description of
   * the meadow
   */
  return "The grass below your feet is soft and green.\n" +
    (flowers_left ? "There are some flowers growing on the meadow.\n" : "" );
}

string flower_long() {
  /* This function is called by the closure for the descr. of the flowers */
  if (flowers_left)
    return "There are some beautiful flowers growing here. Come on, " +
           "pick one.\n";
  else
    return "There are no flowers on the meadow. Someone must have picked " +
           "them.\n";
}

mixed pick_flower() {
  object flower;

  if (flowers_left) {
    flower = clone_object("/domains/example/obj/flower");
    flowers_left--;
    if (transfer(flower, this_player())) {
      move_object(flower, this_object());
      return ({ ({ M_PLAYER, M_PL_VERB, " try", " to pick a flower from the ",
                   "meadow, but it's too heavy, so they dropped it." }) });
    }
    return ({ ({ M_PLAYER, M_PL_VERB, " pick", " a flower from the meadow."
    }) });
  }
}

void configure() {
  object mead;

  set_short("on a meadow");
  set_long(#'room_long);
  set_property(P_OUTSIDE);
  set_exits(({"./room1"}),({"west"}),({0}),({0}),({"west"}));
  set_items(({ ({"flower", "flowers"}), #'flower_long }));
  /* This defines possible actions for the items */
  add_item_actions(({
    ({ ({"flower","flowers"}), "pick <me>", "pick", #'pick_flower })
  }));
}

void populate() {
  if (!present("meadow"))
    move_object(clone_object("/domains/example/obj/meadow_obj"), this_object());
  flowers_left = 15;
}

