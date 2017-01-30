#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(arg)return;
  set_light(1);
  short_desc=RED+"The Myrmidar Mound"+NORM;
  long_desc=
"  The Myrmidar mound is a labyrinthine maze of twisting tunnels that seem\n\
to connect at random.  The tunnels are cool and humid, with a slightly sweet\n\
odor to them.  This is a junction of three tunnels.  The one heading north\n\
seems brighter, while the east and west passages lead further into darkness.\n";
  items=({
    "tunnels", "You see three of them leading off in different directions",
    "junction", "Three tunnels meet here",
    "passages", "The passages are perhaps six feet high, circular, and well-travelled",
  });
  dest_dir=({
   PATH+"xmound.c","out",
    PATH+"mound2.c","west",
    PATH+"mound6.c","east",
  });
}

void init()
{
  ::init();
  add_action("cmd_out","out");
}

int cmd_out(string str)
{
  say(TPN+" leaves out.\n");
  move_object(TP,(object)MAP->query_location(6,4));
  say(TPN+" steps out of the mound.\n");
  command("look",TP);
  return 1;
}
