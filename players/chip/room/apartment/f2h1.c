      /*                                                                    
       *    File: /players/chip/room/apartment/f2h1.c                
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

short_desc = ""+HIK+"A second floor hallway"+NORM+"";

long_desc =
	"You stand in the hallway on the second floor of a long abandoned\n"+
	"apartment building. The walls, floor, and ceiling are all covered\n"+
	"in dirt, dust, mold, and mildew. A strong scent of mold and urine\n"+
	"overwhelms your nostrils, and the holes in the walls give an\n"+
	"indication that someone was either very angry, or just blatently\n"+
	"destructive. There are stairs to the east and the hallway\n"+
	"continues to the west.\n";

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
	"/players/chip/room/apartment/f2h2.c",     "west",
	"/players/chip/room/apartment/f2stairs.c",     "east",
	"/players/chip/room/apartment/apt9.c",     "enter_9",
	"/players/chip/room/apartment/apt10.c",     "enter_10",
	});

}