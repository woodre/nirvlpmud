#include "defs.h"
inherit ROOM;

void on_create() {
  set_area("area");
  set_short("Front Porch");
  set_long("This is more of a landing than a front porch, actually.  It serves its purpose, \
however, which is to provide a spot for Earwax and his roommate, the Midget to sit and \
drink at night.  It also serves as a spot for their landlord to stand \
and hammer on the door, while hollering the only words she knows in \
English, 'When you pay rent!?!'  There are a couple of chairs and an ashtray \
sitting here.");
  add_desc("chair","They are cheap plastic lawn chairs Midget probably stole.");
  add_desc("chairs","They are cheap plastic lawn chairs Midget probably stole.");
  add_desc("ashtray","Just kidding, they refer to the ground as the ashtray when outside.");
  add_exit("down",SWR+"apt1.c");
  add_exit("enter",APTR+"entry.c");
  add_clone(APTM+"repoman.c");
}
