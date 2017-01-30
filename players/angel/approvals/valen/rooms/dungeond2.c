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
  short_desc = HIBLK+"Catacombs of the Magi"+NORM;
  long_desc =
  HIBLK+"  This room is dark and smells like death. The room\n\
  is completely bricked off in all directions. The arched\n\
  ceiling is covered with moss. There is a sarcophagus in the\n\
  middle of the room. The path west leads back to the Lion\n\
  head's fountain. The ground is thick with dust."+NORM+"\n";
  
  items =
  ({

    "dust", 
    "The dust fills the air and covers the floor",
    "pebbles", 
    "Pebbles are scattered everywhere on the floor",
    "floor", 
    "The floor is covered with pebbles and dust",
    "stones", 
    "The bricked stones are old looking",
    "wall",
    "sarcophagus",
    "The sarcophagus could be opened",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonc2.c",     "west",
  });
 
}