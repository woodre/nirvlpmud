      /*                                                                    
       *    File: /players/chip/room/apartment/f2stairs.c                
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

short_desc = ""+HIR+"A second floor stairwell"+NORM+"";

long_desc =
	"This is the stairwell of the second floor of the abandoned\n"+
	"building. The stairs lead up as well as down, and look extremely\n"+
	"dangerous to walk on. It looks like there used to be a banister\n"+
	"along the sides, but it seems to have been long removed.\n"+
	"There is a hallway which leads west into the second floor area.\n";

add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
add_smell("urine", "The scent is strong and makes it difficult to breathe properly");

items =
({
	"stairwell",
	"Very creaky and warped, it still holds just enough to tread upon somehow",
	"banister",
	"It seems to have been removed or rotted away long, long ago",
	"sign",
	"stairs",
	"They lead up to the third floor, as well as down to the first floor",
	});

dest_dir =
({
	"/players/chip/room/apartment/f2h1.c",     "west",
	"/players/chip/room/apartment/f1stairs.c",     "descend",
	"/players/chip/room/apartment/f3stairs.c",     "ascend",
	});

}