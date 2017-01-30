#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("captain"))
    move_object(clone_object(MON_PATH+"goldcloak5.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Tower of the Righteous";
  long_desc = 
"  This chamber is meant to serve as both a meeting room and office\n"+
"for the Goldcloak Captain.  A long mahogany table with stiff-backed\n"+
"chairs on either side of it is in the center of the room.  An open\n"+
"window simultaneously provides a breeze and gives an excellent view\n"+
"of the city.  On the east wall is a tapestry.\n";
  items=({
    "table", "The table is approximately fifteen feet long and four\n"+
             "feet wide.  It is constructed of mahogany and twelve\n"+
             "chairs surround it",
    "chairs", "Perhaps a dozen stiff-backed chairs without cushions surround\n"+
              "the mahogany table in the center of the room",
    "window", "The window provides an excellent view of the city",
    "city", "From the window you can see both the palace and the Royal\n"+
            "Plaza",
    "tapestry", "The tapestry depicts some successful battle between a group\n"+
                "of noble Goldcloaks and a band of fierce warriors.  You\n"+
                "notice that one corner of the tapestry is loose, and that\n"+
                "you could easily 'shift' the tapestry aside",
  });
  dest_dir=({
    PATH+"barrack4.c","down",
  });
}

void init() {
  ::init();
  add_action("cmd_shift","shift");
}

int cmd_shift(string str) {
  if(str!="tapestry") {
    notify_fail("Shift what?\n");
    return 0;
  }
  if(present("captain")) {
    write("The Captain says: Get away from there!\n");
    present("captain")->attack_object(TP);
    return 1;
  }
  write("You shift the tapestry aside and find a hidden room!\n");
  TP->move_player("into a secret passage#"+PATH+"barrack6");
  return 1;
}

