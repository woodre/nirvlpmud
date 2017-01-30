/*
This is an example of a room with a random exit.  This is just one of
dozens of methods of doing random exits, so don't feel like you have
to do it this way.  The other rooms in this directory do random exits
differently, and you can mix and match different methods to suit
your needs.
- Feldegast
*/
#include "defs.h"

inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The void";
  long_desc=
"  You float aimlessly through the void, a field of stars surrounding\n\
you.  You have no conception of up or down, or time and space.  The\n\
only thing you can do is wander.\n";
  items=({
  });
  dest_dir=({
    "blank","wander",
  });
}

init() {
  ::init();
  add_action("cmd_wander","wander");
}

cmd_wander(str) {
  string dest;
  dest=PATH+"random"+random(4);
  say(this_player()->query_name()+" swims through the void.\n");
  write("You wander through the void.\n");
  move_object(this_player(),dest);
  say(this_player()->query_name()+" approaches you through the void.\n");
  command("look",this_player());
  return 1;
}
  
