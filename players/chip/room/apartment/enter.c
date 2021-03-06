      /*                                                                    
       *    File: /players/chip/room/apartment/enter.c                
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

	short_desc = ""+HIK+"A first floor hallway"+NORM+"";

	long_desc =
	"This is a hallway on the first floor of a long-abandoned\n"+
	"apartment building. The walls, floor, and ceiling are all\n"+
	"covered in dirt, dust, mold, and mildew. A strong scent of\n"+
	"mold and urine overwhelms your nostrils, and the holes in\n"+
	"the walls give an indication that someone was either very\n"+
	"angry, or just blatently destructive. The hall continues\n"+
	"to the east, and the exit is to the west.\n";

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
	"/players/chip/room/apartment/f1h1.c",     "east",
	"/room/south/sforst47.c",     "exit",
	"/players/chip/room/apartment/apt1.c",     "enter_1",
	"/players/chip/room/apartment/apt2.c",     "enter_2",
	});

}