/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t11.c    
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
    if( !present("raditz", this_object()) )
  move_object(clone_object("/players/mosobp/areas/TOWER/NPC/raditz.c"), this_object());    
  if(arg) return;
  set_light(1);
  short_desc = BLU+"Kame's Lookout"+NORM;
  long_desc = 
  "  "+HIK+"This is the platform of Kame's Lookout. From here\n"+
  "Kame keeps a watch on the whole earth. Looking around there\n"+
  "are trees all around."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
   
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t12.c",  "east",
    "/players/mosobp/areas/TOWER/rooms/t16.c",  "south",
  });
  return 1;
}  