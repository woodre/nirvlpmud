#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  while(!random(2))
    move_object(clone_object(MON_PATH+"squid.c"),this_object()); /* Sand squids */
  if(arg) return;
  set_light(1);
  short_desc="The Rocks";
  long_desc=
"  The desert is interrupted here by a group of gigantic, jagged\n\
rocks, pointing up into the air like the fingers of some primeval\n\
god of the earth.  Sand pours among the dark black rocks and is\n\
collected in desert tide pools.\n";
  items=({
    "rocks","The gigantic rocks are like an island on a sea of sand, the\n"+
            "only secure footing for miles around.  You may 'enter' them",
    "god","No, it's not really a god",
    "pools","The pools of sand are on the fringes of the rocks.  More secure\n"+
            "footing is to be found higher up",
  });
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
}

void init()
{
  ::init();
  add_action("cmd_enter","enter");
}

int cmd_enter(string str)
{
  notify_fail("Enter what?\n");
  if(!str || (str!="rocks" && str!="the rocks")) return 0;
  say(TPN+" enters the rocks.\n");
  move_object(TP,PATH+"rocks1.c");
  write("You enter the rocks.\n");
  say(TPN+" arrives.\n");
  command("look",TP);
  return 1;
}
