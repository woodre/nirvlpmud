#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("archivist"))
    move_object(clone_object(MON_PATH+"archivist.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This dimly lit chamber appears to have been unearthed recently.  A\n\
pile of rubble is near the door.  Torches are spread around the\n\
chamber to provide light.  A couple of sandstone tables sit in the\n\
middle of the chamber.  The western wall is covered in bookshelves.\n";
  items=({
    "chamber", "At one time it might've been a library",
    "rubble", "Most of the rubble appears to have been cleared away recently",
    "torches", "They provide dim lighting for the room",
    "tables", "At one time they must've been padded, but the padding has\n"+
              "long since moldered",
    "wall", "The western wall is covered in bookshelves",
    "bookshelves", "The bookshelves were part of the sandstone walls once\n"+
                   "Although many of the books have crumbled to dust,\n"+
                   "many of them still remain whole",
    "books", "They are not written in a tongue that you recognize",
  });
  dest_dir=({
    PATH+"castle4.c","east",
  });
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str) {
  if(str!="books" && str!="book") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The books are not written in a tongue that you recognize.\n");
  return 1;
}
