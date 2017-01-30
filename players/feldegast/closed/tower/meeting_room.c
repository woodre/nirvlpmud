#include "/players/feldegast/defines.h"

inherit ROOM;

reset(arg) {
  object board;
  object door;

  if(!present("board")) {
    board=clone_object("/players/feldegast/closed/tower/board");
    move_object(board, this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A meeting room";
  long_desc=
"    This is a well lit room with a long table along its length.\n"+
"Comfortable chairs surround it.  An old sofa lies against the\n"+
"south wall.  This seems like a good place for people to meet and\n"+
"discuss things in a calm and reasonable manner.\n";
  dest_dir=({
    "/players/feldegast/closed/tower/tower1","east"
  });
  door=clone_object("/players/feldegast/std/door.c");
  door->add_id("door");
  door->add_id("oak door");
  door->set_key("nifty staff");
  door->set_locked(1);
  door->set_open_desc("A strong oak door.\n");
  door->set_close_desc("A strong oak door.\n");
  door->set_destination("/players/feldegast/closed/tower/tower1.c");
  door->set_exit("east");
  move_object(door,this_object());
  door->set_partner("door","/players/feldegast/closed/tower/tower1.c");
}

init() {
  ::init();
  add_action("church","church");
}
church() {
  this_player()->move_player("through a secret door#players/feldegast/shrine");
  return 1;
}
