/*                                                                    
 *    File: /players/chip/room/apartment/apt19.c                
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
  if(arg) return;
  set_light(1);
  short_desc = ""+HIW+"A third floor apartment"+NORM+"";
  long_desc =
    "There is absolutely nothing left inside this apartment, and it looks as if there\n"+
    "had recently been someone working to clean it up and repaint the walls and ceiling.\n"+
    "The carpet is gone, seemingly removed in a way to make for the placing of new\n"+
    "carpeting. The hardwood floor beneath looks to have been sanded down and smoothed\n"+
    "out. There is still a stench to the place that matches the rest of the building.\n";

  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  
  items =
  ({
    "walls",
    "About half of the walls look to be freshly painted white",
    "ceiling",
    "It looks to have been freshly painted white recently",
    "carpet",
    "It is gone, so how can you look at it? Try looking at the floor, retard",
    "floor",
    "It is hardwood, slatted, and looks to be prepped for the laying of new wall-to-wall carpeting",
    });

  dest_dir =
  ({
    "/players/chip/room/apartment/f3h2.c",     "hall",
  });
}