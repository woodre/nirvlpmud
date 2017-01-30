#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  int i;
  if(!arg)
  {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  Three tunnels intersect here in an oval shaped room.  The tunnel\n\
to the southeast is unusually narrow, but just large enough for a\n\
human.  The wall to the north seems unusually soft.\n\
  There are three obvious exits: west, northeast, and southeast\n";
    items=({
      "tunnels", "These tunnels don't appear to be well-travelled",
      "tunnel", "It is unusually small.  You could probably fit through it,\n"+
                "but anything larger couldn't",
      "wall", "It is made of dirt and appears to be unusually soft",
    });
    dest_dir=({
      PATH+"mound12.c","west",
      PATH+"mound18.c","northeast",
    });
  }
  if(!present("myrmidar"))
    for(i=random(3); i > 0; i--)
      move_object(clone_object(MON_PATH+((random(2))?"myrm-warrior":"myrm-worker")),this_object());

}
void init() {
  ::init();
  add_action("cmd_se","southeast");
}

int cmd_se(string str)
{
  this_player()->move_player("southeast#"+PATH+"mound16.c");
  return 1;
}

void long()
{
  write(long_desc);
}
