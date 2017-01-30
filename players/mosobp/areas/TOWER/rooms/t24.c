/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t24.c    
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
  "are trees all around. Looking down you can see the tops of\n"+
  "the buildings on Earth."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
    "edge",
    "Looking over the edge you can barely make out the ground far far below",
    "buildings",
    "The tallest buildings of earth can barely be seen from here",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t23.c",  "west",
    "/players/mosobp/areas/TOWER/rooms/t19.c",  "north",
  });
  return 1;
}