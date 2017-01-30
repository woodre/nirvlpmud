/*
 * pub.c
 * same as original, with npc code removed -- Rumplemintz
 */

#include "std.h"
#include "walker.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

#undef EXTRA_LONG
#define EXTRA_LONG if (extra_long(str)) return;

#undef EXTRA_INIT
#define EXTRA_INIT add_action("read", "read");

object pirate1, pirate2, pirate3, pirate4, pirate5;

extra_reset(arg) {

  if (!pirate5) {
    pirate5 = clone_object("/players/padrone/walker/npc/drunk_pirate5");
    move_object(pirate5, this_object());
  }
  if (!pirate4) {
    pirate4 = clone_object("/players/padrone/walker/npc/drunk_pirate4");
    move_object(pirate4, this_object());
  }
  if (!pirate3) {
    pirate3 = clone_object("/players/padrone/walker/npc/drunk_pirate3");
    move_object(pirate3, this_object());
  }
  if (!pirate2) {
    pirate2 = clone_object("/players/padrone/walker/npc/drunk_pirate2");
    move_object(pirate2, this_object());
  }
  if (!pirate1) {
    pirate1 = clone_object("/players/padrone/walker/npc/drunk_pirate1");
    move_object(pirate1, this_object());
  }
}

id(str) {
  return !str || comments_id(str);
}

comments_id(str) {
  return str == "comments" || str == "rude comments" || str == "writing"
      || str == "text" || str == "walls";
}

extra_long(str) {
  if (comments_id(str)) {
    return read(str);
  }
  else
    return 0;
}

read(str) {
  if (comments_id(str)) {
    write("Your cheeks are burning.\n");
    return 1;
  }
  else
    return 0;
}

ONE_EXIT("players/padrone/walker/castle_yard", "west",
     "The pub of the walking castle",
     "You are in what used to be the pub of the walking castle.\n"+
     "This was once a nice and cosy place, where you could take a beer\n"+
     "or a cup of coffee and chat with your friends.\n"+
     "Now the pirates have drunk absolutely everything drinkable,\n"+
     "broken the empty bottles, and written rude comments on the walls.\n", 1)
