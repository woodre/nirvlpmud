#include "../defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=TOWER;
  dest_dir=({
    "/room/lanceroad4","out",
    ROOMPATH+"tower2.c","up",
    ROOMPATH+"public_shop.c","east",
  });
}

void long(string str)
{
  if(this_player() && BOOK)
    write(
"  This is the grand entrance to the Misty Tower.  A solid staircase\n\
with marbled green and blue steps ascends through the center of the\n\
tower.  A pair of stout silverwood tree doors guards the entrance, and\n\
an archway leads east.\n"
    );
  else
    write(
"  The interior of the Misty Tower is surprisingly drab and dusty.  A\n\
stone staircase twists upwards into darkness.  A rickety old door guards\n\
the tower's entrance and an archway leads east.\n"
    );
  write("    There are three exits: up, east, out\n");
}

void init()
{
  ::init();
  if(!BOOK) {
    add_action("cmd_up","northeast");
    write(GRN+"The room around you seems slightly blurry and distorted.\n"+NORM);
  }
}

int cmd_up(string str)
{
  write("You feel disorientated.\n");
  command("look",this_player());
}
