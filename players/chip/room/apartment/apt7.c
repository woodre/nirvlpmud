      /*                                                                    
       *    File: /players/chip/room/apartment/apt7.c                
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
#include <ansi.h>
inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("felon", this_object()) )
    move_object(clone_object("/players/chip/mobs/apartment/dog1.c"),  this_object());
  if(arg) return;
    set_light(1);
	short_desc = ""+HIW+"A first floor apartment"+NORM+"";

	long_desc =
    "This apartment is fairly empty aside from a few kid toys and an old, stained\n"+
    "recliner. The walls and ceiling are somewhat discolored and have grown mold.\n"+
    "There are a couple of unopened cans of food stacked up in the corner on the floor.\n";

  add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
  add_smell("urine", "The scent is strong and makes it difficult to breathe properly");
  
  items =
  ({
    "walls",
    "They are all discolored and you can see the mold growing",
    "floor",
    "Nothing much on the floor, except a few kid toys and cans of food",
    "ceiling",
    "It is very moldy and some of it is hanging loosely, ready to fall",
    "dirt",
    "It is everywhere",
    "dust",
    "It covers almost everything",
    "mold",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "mildew",
    "It is growing in many large spots, due to trapped moisture and humidity",
    "toys",
    "Just a few old Hot Wheels cars and Ninja Turtle figures",
    "recliner",
    "It has some questionable looking stains on it. Sitting down on it probably is not smart",
    "cans",
    "They are covered in dust and god knows what else....besides, they are all expired",
  });

	dest_dir =
	({
	"/players/chip/room/apartment/f1h3.c",     "hall",
	});

}