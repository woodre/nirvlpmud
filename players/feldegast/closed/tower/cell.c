#include "defs.h"
inherit ROOM;
reset(arg) {
  if(!present("protoman")) move_object(clone_object(PATH+"protoman.c"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="The "+HIB+"Crystal"+NORM+" Tower's Foyer";
  long_desc=
"  This is an elegantly furnished room at the bottom of a marble\n"+
"staircase running clockwise up the center of the crystal tower.\n"+
"A smaller staircase leading down is hidden in the marble\n"+
"staircase's arc.  An iron banded oak door, fit for a siege, leads\n"+
"out.\n";
  items=({
  });
  dest_dir=({
    "/players/feldegast/closed/tower/outside","south",
    "/players/feldegast/closed/tower/tower1","up",
    "/players/feldegast/closed/tower/towersub1","down"
  });
}

void init() {
  ::init();
  add_action("local_clone", "protoclone");
  add_action("cmd_read", "protoread");
}

int local_clone(string str) {
  object ob;
  ob=clone_object(str);
  if(!ob) {
    write("Invalid path.\n");
    return 1;
  }
  move_object(ob,TP);
  return 1;
}
cmd_read(str) {
  object read;
  read=present("mailread",TP);
  if(!read) return;
  call_other(read,"read");
  write("Ok.\n");
  return 1;
}
