/*                                                                    
 *    File: /players/chip/room/apartment/apt1.c                
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
  if( !present("bum", this_object()) )
    move_object(clone_object("/players/chip/mobs/apartment/bum1.c"), 

this_object());
  if(arg) return;
  set_light(1);
  short_desc = ""+HIW+"A first floor apartment"+NORM+"";
  long_desc =
    "This apartment has long been vacant, just the same as the rest of the old, run-\n"+
    "down building. There is only a chair left furniture-wise, and where there used to\n"+
    "be a couch is a slightly cleaner section of the carpet...not that it's clean at\n"+
    "all, but by comparison to the rest of the apartment it looks nicer. There are paint\n"+
    "chips, newspapers, and pieces of fiberglass insulation laying everywhere.\n";

  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  
  items =
  ({
    "chair",
    "Just an old, half-rusted, fold-out metal chair",
    "floor",
    "There are lots of paint chips, newspaper, and insulation. You can see where there was once a couch",
    "carpet",
    "It is filthy, except for one only slightly cleaner section where a couch used to be",
    "dirt",
    "It is everywhere",
    "dust",
    "It covers almost everything",
    "mold",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "mildew",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "paint chips",
    "They are all over the floor. They have obviously fallen or been picked off of the wall",
    "chips",
    "They are all over the floor. They have obviously fallen or been picked off of the wall",
    "insulation",
    "There are chunks of it laying around everywhere",
    "newspapers",
    "They cover the floor. They seem to have been made into a bed in the corner",
    "bed",
    "A makeshift bed, formed from alot of newspapers",
    });

  dest_dir =
  ({
    "/players/chip/room/apartment/enter.c",     "hall",
  });
}