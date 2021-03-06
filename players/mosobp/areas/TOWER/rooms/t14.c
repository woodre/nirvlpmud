/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t14.c    
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
  "  "+HIK+"This is the platform of Kame's Lookout. From here\n"+
  "Kame keeps a watch on the whole earth. Looking around there\n"+
  "are trees all around. A couple of bushes are scattered around."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
    "bushes",
    "Plush green bushes scattered around the room",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t15.c",  "east",
    "/players/mosobp/areas/TOWER/rooms/t18.c",  "south",
    "/players/mosobp/areas/TOWER/rooms/t13.c",  "west",
  });
  return 1;
}