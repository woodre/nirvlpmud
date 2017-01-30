/*
 *  File:   /players/mosobp/areas/TOWER/rooms/t1.c
 *  Function:  room
 *  Author(s):  Mosobp@Nirvana
 *  Copyright: copyright (c) 2008 Mosobp
 *             all rights reserved 
 *                                       
 *                                       
 *  Source:  7/17/08
 *  Notes:  
 *  
 *   
 *  Change History:              
 */

#include "/sys/lib.h"

#include "/obj/ansi.h"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
   
  if(arg) return;
  set_light(1);
  short_desc = BLU+"Kame's Tower"+NORM;
  long_desc = 
  "  "+HIB+"This is the base of Kame's Tower looking up the platform\n"+
  "seems to be far in the distance. The air starts to thicken\n"+
  "the farther up the tower you go."+NORM+"\n";
  
  items=
  ({
    "tower",
    "This is a shining surface that appears very slick",
    "platform", 
    "The platform is barely distinguishable from this distance",
  });
  
  dest_dir =
  ({
    "/players/mosobp/areas/BATTLE/rooms/b10.c",  "jump",
    "/players/mosobp/areas/TOWER/rooms/t2.c",    "up",
  });
  return 1;
}