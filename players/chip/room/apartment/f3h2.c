      /*                                                                    
       *    File: /players/chip/room/apartment/f3h2.c                
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

short_desc = ""+HIK+"A third floor hallway"+NORM+"";

long_desc =
	"You stand in the hallway on the third floor of a long abandoned\n"+
	"apartment building. The walls, floor, and ceiling are all covered\n"+
	"in dirt, dust, mold, and mildew. A strong scent of mold and urine\n"+
	"overwhelms your nostrils, and the holes in the walls give an\n"+
	"indication that someone was either very angry, or just blatently\n"+
	"destructive. The hall continues to the east and west.\n";

add_smell("mold", "The scent is strong and makes it difficult to breathe properly");
add_smell("urine", "The scent is strong and makes it difficult to breathe properly");

items =
({
	"walls",
	"They are all covered in filth and peppered with holes of many sizes",
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
	"Holes litter the walls and ceiling, which explains the debris cluttering the floor",
	"trash",
	"Empty beer cans and shreds of newspaper are amongst the rest of the garbage",
	"drywall",
	"There are chunks of it laying around everywhere",
	});

dest_dir =
({
	"/players/chip/room/apartment/f3h3.c",     "west",
	"/players/chip/room/apartment/f3h1.c",     "east",
	"/players/chip/room/apartment/apt19.c",     "enter_19",
	"/players/chip/room/apartment/apt20.c",     "enter_20",
	});

}