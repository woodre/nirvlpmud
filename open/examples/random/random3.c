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
  generate_exits();
}

/*
This generates new destinations for the room's exits, so that
the exits remain the same each time they're used.
*/
generate_exits() {
  string *exits;
  int ran,i;
  exits=({ "random1.c","random2.c","random3.c","random4.c" });
  dest_dir=({ });
  for(i=0; i < 4; i++) {
    ran=random(sizeof(exits));
    dest_dir += PATH+exits[ran];
    exits -= ({ exits[ran] });
    switch(i) {
      case 0: dest_dir+=({ "north" });
              break;
      case 1: dest_dir+=({ "west" });
              break;
      case 2: dest_dir+=({ "east" });
              break;
      case 3: dest_dir+=({ "south" });
              break;
    }
  }
}
