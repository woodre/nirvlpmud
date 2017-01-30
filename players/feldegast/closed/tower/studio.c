#include "/players/feldegast/defines.h"
inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  set_pk(1);
  short_desc="A fencing studio";
  long_desc=
"  This is a large vaulted chamber with a great deal of floorspace\n"+
"for practice fights.  A large stained glass window sheds light into\n"+
"the room from the east.  The walls are covered with decorative but\n"+
"merely aesthetic swords and axes.\n";
  items=({
  });
  dest_dir=({
/*
    "/players/feldegast/closed/tower/tower1","west"
*/
  });
}

void init()
{
  ::init();
  add_action("cmd_quit", "quit");
  TP->set_fight_area();
}

query_no_teleport() { return 1; }
realm() { return "NT"; }

exit()
{
  TP->rm_pk();
}

cmd_quit()
{
  write("You cannot.\n");
  return 1;
}
