/*
Name: chapel.c
Author: Feldegast @ nirvana
Date: 8-17-01
Description:
  The actual chapel of Trelos in the Jal-hab desert.  A priestess here provides healing
and is the source of a quest.  Demons are harmed by entering this place.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg)
{

  if(!present("priestess of trelos"))
    move_object(clone_object(MON_PATH + "priestess.c"), this_object());

  if(arg) return;

  short_desc = CYN + "Chapel of Trelos" + NORM;

  long_desc = 
"  This is a simple, but recently constructed temple dedicated to the\n\
God of Guardians and Protectors, Trelos.  Four rows of pews, padded\n\
with velvet lead up to an altar with a blue shield above it.  Stained\n\
glass windows on the north and south walls let in multicolored light.\n";

  items = ({
    "temple", "reflexive",
    "pews", "They are simple benches constructed of imported wood",
    "velvet", "The pews are padded with velvet covers",
    "altar", "The altar is constructed of white marble with streaks of blue in it",
    "shield", "A blue steel shield has been placed on the wall behind the altar",
    "windows", "The windows depict the Slaughter at Telemak, the Defense of Hatrimek, the\n"+
               "Battle with Kruarg, and the Creation of the Cosmic Wall",
  });

  dest_dir = ({
    "nothing", "out",
  });

  set_light(1);

}

void init()
{
  ::init();
  add_action("cmd_out", "out");
  if((string)TP->query_race() == "demon")
  {
    write(RED+"You feel your skin burn with holy fire!"+NORM+
          "You sense that your kind are not welcome here.\n");
    say(TPN+" is burned by holy fire!\n");
    TP->hit_player(random(350));
  }
}

int cmd_out(string str)
{
  write("You exit the chapel.\n");
  say(TPN+ " exits the chapel.\n");
  move_object(TP, (object)MAP->query_location(1, 6));
    command("look", TP);
  say(TPN + " exits the chapel.\n");
  return 1;
}

