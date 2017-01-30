/*                                                                    
 *    File: /players/chip/room/apartment/apt21.c                
 *    Function: room
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2008 Chip      
 *               All Rights Reserved   
 *    Source: 5/31/08           
 *    Notes:                                                          
 *                                                                    
 *                                                                    
 *    Change History:                                                 
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("addict", this_object()) )
    move_object(clone_object("/players/chip/mobs/apartment/chead2.c"),  this_object());
  if(arg) return;
  set_light(1);
  short_desc = ""+HIW+"A third floor apartment"+NORM+"";
  long_desc =
    "This looks like a gang hideout. There are several bullet holes in the walls and\n"+
    "gang signs spray-painted around the place. Aside from that there's only a few old,\n"+
    "folding metal chairs placed in sort of a circle in the center of the room. There is\n"+
    "an old milk crate right in the center of them with an old piece of plywood on top\n"+
    "of it to be used as a makeshift table.\n";

  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  add_smell("spraypaint", "The scent if it is faint, but still present nonetheless");
  
  items =
  ({
    "walls",
    "They have quite a few bullet holes in them, all about the same size",
    "floor",
    "There is lots of trash, dirt, and chunks of drywall",
    "ceiling",
    "It is very moldy and some of it is hanging loosely, ready to fall as the rest of it already has",
    "dirt",
    "It is everywhere",
    "dust",
    "It covers almost everything",
    "mold",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "mildew",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "holes",
    "The holes are definitely from a gun. Looks like it was probably a 9mm",
    "chairs",
    "They are old, foldable, and steel. There are rusted spots on them",
    "table",
    "It is made from an old milk crate and plywood",
    "crate",
    "One of those kinds that holds four one-gallon jugs",
    "plywood",
    "It is old and beginning to rot away from moisture",
    "gang signs",
    "They are basic insignias used by local gangs to mark their territory",
  });

  dest_dir =
  ({
    "/players/chip/room/apartment/f3h3.c",     "hall",
  });
}