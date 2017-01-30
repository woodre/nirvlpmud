/*
File: 1x6.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 12/24/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=1; y=6;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  The Storncrag mountains tower to the west of you, making further\n\
passage impossible.  A monolith made out of a white marble, streaked\n\
with black, sits at the foot of the mountains.  To the northeast of\n\
you is a copse of trees.\n";
  items=({
    "mountains", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "storncrag", "The mountains to the west of you are tall and frosted with\n"+
                 "snow.  It would be difficult to cross them",
    "hills",     "The hills to the south and west of you are dotted with\n"+
                 "trees",
    "trees",     "Tall, deciduous trees dot the hills",
    "tower",     "The tall black tower sits on top of the highest hill\n"+
                 "for miles around",
    "copse",     "You can just barely make out a building in the middle of the copse",
    "monolith",  "A monolith, approximately three meters tall and constructed out of white\n"+
                 "marble streaked with black, sits on a hill near the bottom of the Storncrags.\n"+
                 "It appears to be quite ancient and has unknown powers.  You can "+BOLD+"touch"+NORM+" it\n"+
                 "if you dare",
  });
  dest_dir=({
    PATH+"1x7.c", "north",
    PATH+"2x6.c", "east",
    PATH+"1x5.c", "south",
  });
}

void init()
{
  ::init();
  add_action("cmd_touch", "touch");
}

int cmd_touch(string str)
{
  if(str!="monolith" && str!="marble")
  {
    notify_fail("Touch what?\n");
    return 0;
  }

  if((int)TP->query_attrib("luc") > random(40))
  {
    write(HIC+"The monolith infuses you with energy!\n"+NORM);
    TP->add_spell_point(40);
  }
  else
  {
    write(HIR+"Fire rips through your body as the monolith strikes you with a bolt of energy!\n"+NORM);
    TP->hit_player(50,"other|electric");
  }

  return 1;
}
