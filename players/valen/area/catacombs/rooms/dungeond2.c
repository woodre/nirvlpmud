/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeond2.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/10/09                                      *
 *    Notes:            dungeon room d 2                              *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIBLK+"<Catacombs of the Magi>"+NORM;
  long_desc =
  HIBLK+"  This room is dark and smells like death. The room is completely\n\
bricked off in all directions. The arched ceiling is covered with\n\
moss. There is a "+BRED+"sarcophagus"+NORM+HIBLK+" in the middle of the room. The path\n\
west leads back to the Lion head's fountain. The ground is thick\n\
with dust and pebbles."+NORM+"\n";
  
  items =
  ({
    "moss",
    "The moss hangs from the ceiling",
    "ceiling",
    "The arched ceiling is over grown with moss",
    "dust", 
    "The dust fills the air and covers the floor",
    "pebbles", 
    "Pebbles are scattered everywhere on the floor",
    "floor", 
    "The floor is covered with pebbles and dust",
    "stones", 
    "The bricked stones are old looking",
    "wall",
    "The walls are made of stoned bricks",
    "sarcophagus",
    "The sarcophagus is ancient. The symbols on the\n"+
    "sarcophagus have fallen off years ago. You\n"+
    "could "+RED+"open sarcophagus"+NORM+" and see what is inside\n",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonc2.c",     "west",
  });
}

int sarcophagus1;

init() 
{ ::init();
  add_action("open","open");
}

open(str)
{ 
  if(str == "sarcophagus")
  {
	if(sarcophagus1 == 0)
	{
	  sarcophagus1 = 1;
	  write("The cover of the sarcophagus slides off with\n"+
      "ease. As the cover of the sarcophagus is almost half way\n"+
      "off. A manically laugh is heard from inside the sarcophagus\n"+
      "A "+CYN+"bony hand"+NORM+" pushs the cover off completely.\n"+
      "A "+CYN+"skeleton"+NORM+" arises from the sarcophagus!\n");
      move_object(clone_object("/players/valen/area/catacombs/mobs/skeleton.c"), this_object());
      return 1;
    }
    else write("The sarcophagus has already been opened.\n");
    return 1;
  }
  else write("Open what?");
  return 1;
}