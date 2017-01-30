/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t3.c    
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
  "seems to be far in the distance. Lightening strikes around\n"+
  "you as you enter the clouds."+NORM+"\n";
  
  items=
  ({
    "tower",
    "This is a shining surface that appears very slick",
    "platform",
    "The platform is barely distinguishable from this distance",
    "lightening",
    "Flashes of lightening light up the sky",
    "clouds",
    "Fluffy white clouds surrounding the tower",
  });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t4.c",  "up",
    "/players/mosobp/areas/TOWER/rooms/t2.c",  "down",
  });
  return 1;
}
