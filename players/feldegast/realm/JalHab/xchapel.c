/*
Name: xchapel.c
Author: Feldegast @ nirvana
Date: 8-17-01
Description:
  The maproom for the Chapel of Trelos in the Jal-hab desert.
*/
#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{

  if(arg) return;

  set_light(1);

  short_desc = CYN + "Chapel of Trelos" + NORM;

  long_desc =
"  A newly constructed chapel stands in the midst of two blackened\n\
hills in the middle of the wasteland.  The chapel is small and humble,\n\
but well-made and maintained.  Above the doorway to the chapel is a\n\
blue shield, the symbol of the Order of the Wall.\n";

  items = ({
    "chapel", "A newly made chapel constructed of sandstone and dedicated to Trelos\n"+
              "sits here in the middle of the desert.  You may "+BOLD+"enter"+NORM+" the chapel",
    "shield", "A steel shield, painted blue has been placed over the entrance to the chapel",
    "doorway", "A pair of double doors constructed out of imported wood lead inside",
    "hills", "Two black hills stand on either side of the white chapel",
    "symbol", "A steel shield, painted blue, has been placed over the entrance to the chapel",
  });

  dest_dir = ({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });

}

void init()
{
  ::init();
  add_action("cmd_enter", "enter");
}

int cmd_enter(string str)
{
  if(str=="chapel" || str=="church")
  {
    write("You enter the chapel.\n");
    say(TPN+" enters the chapel.\n");
    move_object(TP, PATH+"chapel.c");
    command("look", TP);
    say(TPN+" enters the chapel.\n");
    return 1;
  }
  else return 0;
}

