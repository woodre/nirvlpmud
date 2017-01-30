/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeona2.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room a 2                              *
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
  if( !present("vermin", this_object()) )
  {
    move_object(clone_object("/players/valen/area/catacombs/mobs/vermin.c"), this_object());
  }
  short_desc = HIBLK+"<Catacombs of the Magi>"+NORM;
  long_desc =
  HIBLK+"  This part of the catacomb is much smaller than the\n\
atrium. Even the pillars here are much smaller. One\n\
pillar has succumbed to the wrath of time. There are\n\
few torches hanging on the pillars. The ceiling is\n\
now visible with roots dangling from it. There is a\n\
huge arched gateway place along the wall here. There\n\
appears to be some type of glowing runes on the arched\n\
gateway."+NORM+"\n";

  items =
  ({
    "catacomb",
    "The catacomb path goes in two directions. North and East",    
	"torch",
    "The torch is secured to the wall and cannot be removed",
    "dust",
    "The dust fills the air and covers the floor",
    "pebbles",
    "Pebbles are scattered everywhere on the floor",
    "floor",
    "The floor is covered with pebbles and dust",
    "stones",
    "The bricked stones are old looking",
    "pillars",
    "A connecting support beam from the floor to the ceiling",
    "wall",
    "The wall is made from stoned bricks",
    "gateway",
    "The arched gateway is made from some type of unknown stone",
    "runes",
    "You cannot decipher the runes on the gateway",
    "ceiling",
    "The ceiling is just moss and roots now",
    "pillar",
    "The broken pillar blocks the path to the south",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeona1.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeonb2.c",     "east",
  });
}