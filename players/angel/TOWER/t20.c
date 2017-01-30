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
  if( !present("nappa", this_object()) )
  move_object(clone_object("/players/mosobp/areas/TOWER/NPC/nappa.c"), this_object());    
  if(arg) return;
  set_light(1);
  short_desc = BLU+"Kame's Lookout"+NORM;
  long_desc = 
  "  "+HIK+"This is the platform of Kame's Lookout. From here\n"+
  "Kame keeps a watch on the whole earth. Looking around there\n"+
  "are trees all around. A couple of statues are scattered around."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
    "statues",
    "Statues erected for the Z fighters for saving Earth",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t16.c",  "north",
    "/players/mosobp/areas/TOWER/rooms/t21.c",  "east"
  });
  return 1;
}