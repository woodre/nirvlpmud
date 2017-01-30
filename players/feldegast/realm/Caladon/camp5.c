/*
File: camp5.c
Author: Feldegast
Date: 11/08/01
Description:
  An orc camp.  Beneath the temple.
*/

#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(!present("orcish hero"))
    move_object(clone_object(MON_PATH+"orchero.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  At the foot of the hill, the orcs have fashioned a strange pantheon\n\
of brightly painted straw men.  A flight of stone steps lead up the side\n\
of the mountain to a temple high above.  A winding path leads southwest\n\
towards the river.\n";

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
    "hill",       "The hill leads into the mountains to the west",
    "path",       "The path leads southwest towards the river",
    "mountain",   "The uncrossable Storncrag mountains rise to the west",
    "steps",      "Several hundred steps rise at a 45 degree angle halfway up the side of the\n"+
                  "mountain where they end at a temple that the orcs have captured",
    "straw men",  "The bizarre figures consist of burlap bags stuffed with straw and painted in\n"+
                  "bright, war-like colors.  The purpose of the straw men is unknown",
    "men",        "The bizarre figures consist of burlap bags stuffed with straw and painted in\n"+
                  "bright, war-like colors.  The purpose of the straw men is unknown",
    "river",      "The River Xian passes to the south of the orc encampment.  To the west, the\n"+
                  "water becomes more frothy and agitated",
  });

  dest_dir = ({
    PATH+"camp8.c", "climb",
    PATH+"camp2.c", "east",
    PATH+"camp6.c", "southwest",
  });

}

void init()
{
  ::init();
  add_action("cmd_block", "climb");
}

int cmd_block(string str)
{
  if(present("orc") && (string)TP->query_race() != "orc")
  {
    write("The orc blocks your way.\n");
    return 1;
  }
}
