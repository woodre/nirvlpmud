/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t13.c    
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
  if( !present("garlicjr", this_object()) )
  move_object(clone_object("/players/mosobp/areas/TOWER/NPC/garlicjr.c"), this_object());      
  if(arg) return;
  set_light(1);
  short_desc = BLU+"Kame's Lookout"+NORM;
  long_desc = 
  "  "+HIK+"This is the edge of Kame's Lookout. From here\n"+
  "Kame keeps a watch on the whole earth looking around there\n"+
  "are trees all around. There is a house to the south."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
    "edge",
    "Looking over the edge you can barely make out the ground far far below",
    "house",
    "Kame's house can be seen to the south",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t14.c",  "east",
    "/players/mosobp/areas/TOWER/rooms/t12.c",  "west",
    "/players/mosobp/areas/TOWER/rooms/t10.c",  "south",
  });
  return 1;
}