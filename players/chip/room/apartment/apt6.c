      /*                                                                    
       *    File: /players/chip/room/apartment/apt6.c                
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

	short_desc = ""+HIW+"A first floor apartment"+NORM+"";

	long_desc =
	"This apartment has long been vacant, just the same as the rest of\n"+
	"the old, run down building. There is nothing left furniture-wise,\n"+
	"but you can see where some wads of newspaper have been used for a\n"+
	"makeshift bed. There are a couple unopened cans of food amongst\n"+
	"all the nastiness. I wouldn't chance trying them though, as they\n"+
	"seem to have been there a very long time.\n";

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
	"newspaper",
	"It is wall wadded up and piled up to make what could be considered a bed of some sort",
	"cans",
	"They are covered in dust and god knows what else....besides, they're all expired",
	"bed",
    "A makeshift bed, formed from alot of newspapers",
	});

	dest_dir =
	({
	"/players/chip/room/apartment/f1h2.c",     "hall",
	});

}