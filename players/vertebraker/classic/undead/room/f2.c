#include <ansi.h>
#include "../lib/guild_defs.h"

inherit G_HALL;

void reset(status arg)
{
   if(arg) return;
   set_light(-5);
   set_short(CEN);
   set_long("\
  You have entered the courtyard of " + CEN + ".\n\
Darkness has penetrated the innermost pores of this citadel.\n\
The courtyard is cold and barren, along with being entirely\n\
devoid of any form of life.\n\n\
Wait- what's that shadow?\n\
You swear you saw something out of the corner of your eye,\n\
but you blinked and he was gone.\n\
To the north, you see the main gates to the castle. They stand\n\
open, with tall statues guarding the passageway. To the south\n\
is the drawbridge, while to the east and west lie the two stair-\n\
cases leading up to the twin towers of the castle.\n");
  add_item(({"courtyard","shadow","gates","castle","statues",
             "passageway","drawbridge","staircase","staircases",
             "twin towers", "towers"}), "");
  set_exits(({
ROOMDIR + "f3", "north",
ROOMDIR + "f1", "south",
 }));
}
