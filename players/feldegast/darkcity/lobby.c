#include "def.h"

inherit MYROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A motel lobby";
  long_desc=
"     This is the lobby of a seedy looking motel.  An elevator is to\n\
the right of the clerk's desk and a pair of double doors leads out to\n\
the south.\n";
  items=({
    "desk","A long desk where the clerk sits.  There's an open registry book\n"+
           "on it",
    "book","An open registry book which you can read",
    "doors","A pair of wide double doors leading out onto the street",
    "elevator","From the look of this elevator, you have fair odds of surviving\n"+
               "a short trip"
  });
  dest_dir=({
    PATH+"street2","south",
    PATH+"hallway","up"
    
  });
}

init() {
  ::init();
  add_action("cmd_read","read");
}

cmd_read(str) {
  if(!str && str!="book") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("According to the registry, John Murdoch has been renting a room\n"+
        "here for three weeks.\n");
  say(this_player()->query_name()+" reads the registry book.\n");
  return 1;
}

