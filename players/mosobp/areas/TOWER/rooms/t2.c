/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t2.c    
 *  Function:  room                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved            
 *                                       
 *                                       
 *  Source:  6/17/08                     
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
  "seems to be far in the distance. The clouds starts to surround\n"+
  "the tower."+NORM+"\n";
  
  items=
  ({
    "tower",
    "This is a shining surface that appears very slick",
    "platform",
    "The platform is barely distinguishable from this distance",
    "clouds",
    "White puffy clouds floating in the breeze",
  });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t3.c",  "up",
    "/players/mosobp/areas/TOWER/rooms/t1.c",  "down",
  });
  return 1;
}
