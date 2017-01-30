      /*                                                                    
       *    File: /players/chip/room/apartment/f3stairs.c                
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

if(arg) return;

set_light(1);

short_desc = ""+HIR+"A third floor stairwell"+NORM+"";

long_desc =
	"This is the stairwell of the third floor of the abandoned\n"+
	"building. The stairs lead downward, and look extremely dangerous\n"+
	"to walk on. You can see where there used to be a banister along\n"+
	"the sides, but it seems to have been long removed. There is a \n"+
	"hallway which leads west into the third floor hallway.\n";

add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
add_smell("urine", "The scent is strong and makes it difficult to breathe properly");

items =
({
	"stairwell",
	"Very creaky and warped, it still holds just enough to tread upon somehow",
	"banister",
	"It seems to have been removed or rotted away long, long ago",
	"stairs",
	"They lead down to the second floor",
	});

dest_dir =
({
	"/players/chip/room/apartment/f3h1.c",     "west",
	"/players/chip/room/apartment/f2stairs.c",     "descend",
	});

}