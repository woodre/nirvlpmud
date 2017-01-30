inherit "room/room";
#include "definitions.h"


init()
{
  string phase;
  ::init();
  phase = call_other(CASTLEROOM+"/moonshrine.c", "query_month");
  if (phase == "dark")
  {
    write("The moonlight is too faint... you get lost.\n");
    move_object(TP, CASTLEROOM+"/forestpath2.c");
    return;
  }
  add_action("goplace", "enter");
}


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=("Dark Forest");
    long_desc=
"     The ruins of what was the greatest Sithi City stretch before you.\n"+
"Enki-o Shao'saye, sadly, is now nothing but barely recognizable marble\n"+
"formations and rubble. The ruins have been so overgrown that they\n"+
"barely exist at all. You may 'enter' the city.\n";

    dest_dir=({
CASTLEROOM+"/forestpath2.c","south"  ,
    });

    items=({
"ruins",     "     Enki-o Shao'saye is the ruins of an ancient Sithi city",
"rubble",    "     The rubble of marble buildings lie hidden in the vegetation",
"formations","     Various marble slabs and pillars lay under trees and bushes",
"city",      "     Enki-o Shao'saye is the ruins of an ancient Sithi city",
    });
  }
}


goplace()
{
   say(TPN+" enters the city of the Sithi.\n");
   write("You enter the city of the Sithi.\n");
   move_object(TP, CASTLEROOM+"/shaosaye.c");
   return 1;
}
