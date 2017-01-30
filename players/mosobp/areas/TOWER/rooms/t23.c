/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t23.c    
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
  "Kame keeps a watch on the whole earth looking around there\n"+
  "are trees all around. There is a statue in the middle\n"+
  "of the room."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
    "edge",
    "Looking over the edge you can barely make out the ground far far below",
    "statue",
    "A statue has been erected to Goku and put here",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t24.c",  "east",
    "/players/mosobp/areas/TOWER/rooms/t22.c",  "west",
    "/players/mosobp/areas/TOWER/rooms/t18.c",  "north",
  });
  return 1;
}