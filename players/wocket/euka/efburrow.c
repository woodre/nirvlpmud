#include "/players/wocket/closed/ansi.h"
#include "Def.h"
inherit EROOM;

reset(arg){
 object tree;
  if(!present("yestler"))
    move_object(EPATH+"NPC/yestler.c",this_object());
  if(arg){ return; }
  short_desc = GRN+"The Euka Forest"+OFF;
  long_desc = YEL+"   "+
  "The walls of this small burrow are made of the earth above it.\n"+
  "Roots and vines stick out from the walls supporting many of the\n"+
  "nicknacks used during daily life.  A small hammock hangs in the\n"+
  "corner, surrounded by hundreds of books.\n"+OFF;
  items = ({
  "walls","They are made of packed dirt",
  "roots","Large and grey, they stick out from the walls",
  "vines","Long and thin vines stick out from the dirt walls",
  "nicknacks","Pictures, pots, pans, coats, and other such useful things.\n",
  "hammock","A large net hammock which fills a corner of the burrow",
  "books","Stacks of different sized and colored books fill the floor",
  });
  smells = ({
  "default","You smell dirt and musk",
  });
  listens = ({
  "It is very quiet here",
  });
  dest_dir = ({
  EPATH+"ef9.c","out",
  });
  set_light(1);
}
