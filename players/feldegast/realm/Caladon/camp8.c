/*
File: camp8.c
Author: Feldegast
Date: 03/16/02
Description:
  An orc camp.  Before the temple.
  Note to self: Orc chieftein goes here.
*/

#include "defs.h"

inherit ROOM;

int action;

void reset(int arg)
{
  if(arg) return;
  no_clean = 1;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  At the top of the flight of stone steps a tall bonfire burns in a\n\
deep pit filled with wood and black pitch.  A stone temple, obviously\n\
of human construction but defiled by the orcs, is to the west.  At\n\
the bottom of the stone steps is the orc encampment.\n";
  items = ({
    "bonfire",    "At the bottom of a circular pit fashioned from stone, a bonfire burns hot",
    "pit",        "At the bottom of a circular pit fashioned from stone, a bonfire burns hot",
    "wood",       "At the bottom of a circular pit fashioned from stone, a bonfire burns hot",
    "pitch",      "At the bottom of a circular pit fashioned from stone, a bonfire burns hot",
    "encampment", "The encampment consists of perhaps a dozen tents and several wooden buildings",

    "huts",       "They are poorly constructed, but servicable",
    "temple",     "The temple appears to be small, but ornate.  A bonfire blazes in the courtyard\n"+
                  "in front of it",
    "mountain",   "The uncrossable Storncrag mountains rise to the west",
    "steps",      "Several hundred steps rise at a 45 degree angle halfway up the side of the\n"+
                  "mountain where they end at a temple that the orcs have captured",
    "river",      "The River Xian passes to the south of the orc encampment.  To the west, the\n"+
                  "water becomes more frothy and agitated",
  });

  dest_dir = ({
    PATH+"camp5.c", "descend",
    PATH+"camp9.c", "west",
  });

  /* Only clone the orc mage once per reboot. */
  move_object(clone_object(MON_PATH+"orcmage.c"),this_object());

}

void init()
{
  ::init();
  add_action("cmd_block", "west");
  if(!action)
    call_out("summon", 3);
}

int cmd_block(string str)
{
  if((present("orc") || present("pit fiend")) && (string)TP->query_race() != "orc")
  {
    write("The orc blocks your way.\n");
    return 1;
  }
}

void summon()
{
  if(!action && present("kagatu"))
  {
    tell_room(this_object(), "Kagatu casts a burning powder into the burning pit as he utters a few words.\n"+
                        BOLD+"\t\tVaash thraas kunaak dlotak!\n"+NORM);
    action = 1;
    call_out("rise", 3);
  }
}

void rise()
{
  tell_room(this_object(), BOLD+BLK+"\nA pit fiend rises from the flames!\n\n"+NORM);
  move_object(clone_object(MON_PATH+"pitfiend.c"), this_object());
  call_out("flee", 3);
}

void flee()
{
  object ob;
  ob=present("orc shaman", this_object());
  if(ob) command("west", ob);
}
