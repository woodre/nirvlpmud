/*
File: camp6.c
Author: Feldegast
Date: 11/08/01
Description:
  A waterfall near the orc camp.
*/

#include "defs.h"

inherit ROOM;

int summoned;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  A large waterfall froths fitfully at the foot of the Storncrag\n\
mountains.  At the bottom of the fall a small pond, filled with rocks,\n\
churns violently before heading downhill to the east.  A path leads\n\
behind the waterfall, and back to the northeast towards an orc\n\
encampment.\n";

  items = ({
    "encampment", "The encampment consists of perhaps a dozen tents and several wooden buildings\n"+
                  "further up the side of the mountains is a temple of some sort that\n"+
                  "the orcs have taken over",
    "orcs",       "You can see a few orcs milling around inside the encampment",
    "bailey",     "The bailey is several hundred feet long and consists of tree trunks\n"+
                  "lashed together by leather ropes.  Primitive, but effective",
    "huts",       "They are poorly constructed, but servicable",
    "temple",     "The temple appears to be small, but ornate.  A bonfire blazes in the courtyard\n"+
                  "in front of it",
    "path",       "The path leads northeast towards the encampment",
    "mountain",   "The uncrossable Storncrag mountains rise to the west",
    "river",      "The River ______ passes to the south of the orc encampment.  To the west, the\n"+
                  "water becomes more frothy and agitated",
    "waterfall",  "The waterfall is easily sixty feet tall and perhaps thirty feet wide",
  });

  dest_dir = ({
    PATH+"camp7.c", "west",
    PATH+"camp5.c", "northeast",
  });

}

void init()
{
  ::init();
  add_action("cmd_block", "west");
}

int cmd_block(string str)
{
  if(!summoned)
  {
    write(BLU+"As you approach the waterfall, a fierce creature rises up out of the pond!\n"+NORM);
    say("As "+TPN+" approaches the waterfall, a fierce creature rises up out of the pond!\n"+NORM);
    move_object(clone_object(MON_PATH+"aquademon.c"), this_object());
    summoned = 1;
    return 1;
  }
  if(present("water demon"))
  {
    write("The water demon blocks your way.\n");
    TP->attacked_by(present("water demon"));
    return 1;
  }
}
