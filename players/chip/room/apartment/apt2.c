/*                                                                    
 *    File: /players/chip/room/apartment/apt2.c                
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
  if( !present("dealer", this_object()) )
    move_object(clone_object("/players/chip/mobs/apartment/cdeal1.c"),  this_object());
  if(arg) return;
  set_light(1);
  short_desc = ""+HIW+"A first floor apartment"+NORM+"";
  long_desc =
    "It looks as if a tornado ripped through this shambles of what was something you\n"+
    "could almost call an apartment. There is a couch and recliner in the center of\n"+
    "the room, and an old coffee table right in front of them. On the wall there are\n"+
    "a few old posters and a couple of faded photographs. The smell here is more than\n"+
    "overwhelming.\n";

  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  
  items =
  ({
    "couch",
    "It has some disgusting looking stains on it, and many ripped spots.",
    "stains",
    "A few of them look like blood stains",
    "recliner",
    "It has a few tears in the fabric, and some pretty nasty looking stains",
    "table",
    "The table is empty aside from some stains and burned spots. It is missing a leg",
    "dirt",
    "It is everywhere",
    "dust",
    "It covers almost everything",
    "mold",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "mildew",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "wall",
    "It is very discolored. There are a few old posters and photographs pinned up",
    "posters",
    "There are two which depict Jimi Hendrix in concert, and a couple with wierd, almost hypnotic designs",
    "photographs",
    "They are too faded to make out anything more than the outline of a person",
    });

  dest_dir =
  ({
    "/players/chip/room/apartment/enter.c",     "hall",
  });
}