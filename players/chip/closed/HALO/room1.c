/*                                                                    
 *    File: /players/chip/closed/other/HALO/room1.c               
 *    Function: room
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2013 Chip      
 *               All Rights Reserved   
 *    Source: 1/11/13          
 *    Notes:                                                          
 *                                                                    
 *                                                                    
 *    Change History:                                                 
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/room/room";

this_object());
  if(arg) return;
  set_light(1);
  short_desc = ""+HIG+"Pillar of Autumn: Airlock"+NORM+"";
  long_desc =
    "This is the entrance airlock to the UNSC ship, "+HIG+"Pillar of Autumn"+NORM+". There is a control\n"+
    "panel on the wall next to each door, one in front of you, and one behind. One\n"+
    "leads inside the Autumn, the other leads back outside to the world you have come to\n"+
    "to know so well. From beyond the door ahead comes the deep voice of a man. It sounds\n"+
    "like he's speaking to a female comrade.\n";

  
  items =
  ({
    "panel",
    "There are two here, the front panel, and the rear panel",
    "panels",
    "There are two here, the front panel, and the rear panel",
    "front panel",
    "This panel allows you to 'enter' the "+HIG+"Pillar of Autumn"+NORM+"",
    "rear panel",
    "This panel allows you to 'exit' back to the outside world",
    "airlock",
    "The basic entry chamber that can be found on any space vehicle",
    "doors",
    "One leads out, the other leads inside the ship. Each has a control panel beside it",
    });

  dest_dir =
  ({
    "/players/chip/closed/other/HALO/room2.c",     "enter",
    "/players/chip/room/apartment/enter.c",     "hall",
  });
}