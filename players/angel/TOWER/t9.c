/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t9.c    
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
  "  "+HIB+"This is the pillar of Kame's Tower looking up the platform\n"+
  "seems to be looming overhead. Looking down the ground\n"+
  "appears to be just a speck of amidst a bigger backdrop."+NORM+"\n";
  
  items=
  ({
    "tower",
    "This is a shining surface that appears very slick",
    "platform",
    "The platform is almost within reach",
    "ground",
    "The trees are becoming a blur against the bigger backdrop",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/dummy/t10.c",  "up",
    "/players/mosobp/areas/TOWER/rooms/t8.c",         "down",
  });
  return 1;
}
