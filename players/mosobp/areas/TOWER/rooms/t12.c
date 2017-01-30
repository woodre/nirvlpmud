/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t12.c    
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
  short_desc = BLU+"Kame's Lookout"+NORM;
  long_desc = 
  "  "+HIK+"This is the edge of Kame's Lookout. From here\n"+
  "Kame keeps a watch on the whole earth. Looking around there\n"+
  "are trees all around. A tree stands in the middle of the room."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
    "edge",
    "Looking over the edge you can barely make out the ground far far below",
    "tree",
    "A giant 50 foot tall tree in the middle of the room",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t13.c",  "east",
    "/players/mosobp/areas/TOWER/rooms/t11.c",  "west",
    "/players/mosobp/areas/TOWER/rooms/t17.c",  "south",
  });
  return 1;
}